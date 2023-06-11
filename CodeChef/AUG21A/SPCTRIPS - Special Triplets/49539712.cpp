#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int ans[M];
int Cal(const int& n)
{
    int i,j,l,m,r;
    for(i=1;i<=n;i++)
    {
        ans[i]=0;
        for(j=i+i;j<=n;j+=i)
        {
            l=0,r=n/j;
            while(l <= r)
            {
                m=(l+r) >> 1;
                if(i+j*m <= n)l=m+1;
                else r=m-1;
            }
            ans[i]+=l;
        }
        ans[i]+=ans[i-1];
    }
    return ans[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << Cal(n) << '\n';
    }
    return 0;
}