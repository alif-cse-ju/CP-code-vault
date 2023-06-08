#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
bool mark[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0,g,i,j,n,x;
    cin >> n;
    for(i=0;i<n;i++)cin >> x, mark[x]=1;
    for(i=N-5;i;i--)
    {
        if(mark[i])continue;
        g=0;
        for(j=i+i;j<N;j+=i)
        {
            if(mark[j])g=__gcd(g, j);
        }
        if(g == i)mark[i]=1;
    }
    for(i=1;i<N-4;i++)ans += mark[i];
    cout << ans-n;
    return 0;
}