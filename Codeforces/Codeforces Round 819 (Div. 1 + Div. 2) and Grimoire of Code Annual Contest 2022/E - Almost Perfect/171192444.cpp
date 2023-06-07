#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;
ll dp[M],fact[M],invFact[M];
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
 void PreCal()
{
    dp[0]=dp[1]=fact[0]=1;
    for(int i=2;i<M;i++)dp[i]=(dp[i-1] + dp[i-2]*(i-1)) % mod;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1] * i) % mod;
    invFact[M-1]=BigMod(fact[M-1],mod-2);
    for(int i=M-2;i>=0;i--)invFact[i]=(invFact[i+1] * (i+1)) % mod;
}
 ll nCr(int n,int r)
{
    if(n < r)return 0;
    return (fact[n] * ((invFact[r] * invFact[n-r]) % mod)) % mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        ll ans=0;
        for(int i=0;4*i<=n;i++)
        {
            ll tmp=dp[n-4*i];
            tmp = (tmp * nCr(n-2*i, 2*i)) % mod;
            tmp = (tmp * fact[2*i]) % mod;
            tmp = (tmp * invFact[i]) % mod;
            ans += tmp;
            if(ans >= mod)ans -= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}