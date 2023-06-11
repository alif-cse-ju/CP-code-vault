#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int a[M];
ll dp[M],sum[M];
void Update(int i,int v)
{
    while(i < M)sum[i]=(sum[i]+v)%mod, i += (i & -i);
}
ll Query(int i)
{
    ll ans=0;
    while(i)ans=(ans+sum[i])%mod, i -= (i & -i);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    ll ans=1,tmp;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        tmp=Query(a[i]-1);
        dp[i]=(tmp+1)%mod;
        Update(a[i],dp[i]);
        ans=(ans+dp[i])%mod;
    }
    cout << ans;
    return 0;
}