#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
//template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e2+5;
const int N=1e6+5;
const int mod=998244353;
int x;
ll dp[M][M],fact[M],ncr[M][M];
ll BigMod(ll val,ll pow)
    ll res = 1;
    val = val % mod;
    while(pow)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
void Fact()
{
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
}
 ll nCr(int n,int r)
{
    if(n < r)return 0;
    if(ncr[n][r] != -1)return ncr[n][r];
    return ncr[n][r]=(fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}
 ll DP(int rem,int last)
{
    if(!rem)return 1;
    if(rem == 1  ||  last == x)return 0;
    ll &ans=dp[rem][last];
    if(ans != -1)return ans;
    ans=0;
    ll tmp;
    int i,mx=min(rem-1,x-last);
    for(i=0;i<=rem;i++)
    {
        tmp=(nCr(rem,i)*BigMod(mx,i))%mod;
        tmp=(tmp*DP(rem-i,last+mx))%mod;
        ans += tmp;
        if(ans >= mod)ans -= mod;
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> x;
    Fact();
    memset(dp,-1,sizeof(dp));
    memset(ncr,-1,sizeof(ncr));
    cout << DP(n,0);
    return 0;
}