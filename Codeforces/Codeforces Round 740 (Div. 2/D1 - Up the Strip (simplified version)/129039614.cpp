#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int m,n;
ll sum[M];
void Update(int i,int v)
    while(i <= n)
    {
        sum[i] += v;
        i += (i & -i);
    }
ll Query(int i)
    ll ans=0;
    while(i)
    {
        ans += sum[i];
        i -= (i & -i);
    }
    return ans%m;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tmp;
    int i,j,l,r;
    cin >> n >> m;
    Update(n,1);
    for(i=n-1;i;i--)
    {
        tmp=Query(n);
        for(j=2;j*i <= n;j++)
        {
            l=i*j-1,r=min(n,(i+1)*j-1);
            tmp += Query(r) - Query(l);
            tmp %= m;
        }
        if(tmp < 0)tmp += m;
        Update(i,tmp);
    }
    cout << Query(1);
    return 0;
}