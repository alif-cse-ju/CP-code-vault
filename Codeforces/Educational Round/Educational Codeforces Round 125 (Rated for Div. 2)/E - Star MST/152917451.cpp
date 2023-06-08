#pragma GCC optimize("Ofast")
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
const int N=2e6+5;
const int mod=998244353;
const int sz = 255;
ll dp[sz][sz],k,n,ncr[sz][sz];
long long BigMod(long long val,long long pow)
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
 ll nCr(int n,int r)
{
    if(r > n)return 0;
    if(!n  ||  !r)return 1;
    ll &ans=ncr[n][r];
    if(ans > -1)return ans;
    ans=nCr(n-1,r) + nCr(n-1,r-1);
    if(ans >= mod)ans -= mod;
    return ans;
}
 ll Cal(ll n)
{
    return (n*(n-1))/2;
}
 ll DP(int nichi,int mx)
{
    if(nichi == n)return 1;
    if(mx > k)return 0;
    ll &ans=dp[nichi][mx];
    if(ans > -1)return ans;
    ans=DP(nichi,mx+1);
    ll tmp;
    for(int i=1;i<=n-nichi;i++)
    {
        tmp=(nCr(n-nichi, i) * BigMod(k-mx+1, Cal(i+nichi)-Cal(nichi)))%mod;
        ans=(ans+(tmp*DP(i+nichi, mx+1))%mod)%mod;
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    memset(ncr,-1,sizeof(ncr));
    --n, cout << DP(0, 1);
    return 0;
}