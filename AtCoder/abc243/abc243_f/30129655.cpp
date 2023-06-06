#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;

const int sz = 55;

int m,n;
ll dp[sz][sz][sz],fact[sz],invFact[sz],w[sz];

long long BigMod(long long val,long long pow)
{
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

void PreCal()
{
    int i=0;
    fact[0]=1;
    for(i=1;i<sz;i++)fact[i]=(fact[i-1]*i)%mod;
    invFact[sz-1]=BigMod(fact[sz-1],mod-2);
    for(i=sz-1;i;i--)invFact[i-1]=(invFact[i]*i)%mod;
}

ll DP(int id,int rem,int distinct)
{
    if(id > n  &&  !rem  &&  distinct == m)return 1;
    if(id > n  ||  rem < 0  ||  distinct > m)return 0;
    ll &ans=dp[id][rem][distinct];
    if(ans > -1)return ans;
    ans=0;
    for(int i=0;i<=rem;i++)
    {
        ans += (((DP(id+1,rem-i,distinct+min(1,i)) * BigMod(w[id],i))%mod) * invFact[i])%mod;
        if(ans >= mod)ans -= mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k;
    ll ans,wTot=0;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)cin >> w[i], wTot += w[i];
    PreCal();
    memset(dp,-1,sizeof(dp));
    ans=(fact[k] * BigMod(BigMod(wTot,k),mod-2))%mod;
    ans=(ans * DP(1,k,0))%mod;
    cout << ans;
    return 0;
}
