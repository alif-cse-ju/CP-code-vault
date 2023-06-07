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
const int N=5e6+5;
const int mod=998244353;

const int sz = 5e3+5;

int cnt[sz],n;
ll dp[sz][sz],fact[sz],invFact[sz];

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
    fact[0]=1;
    for(int i=1;i<=sz-5;i++)fact[i]=(fact[i-1]*i)%mod;
    invFact[sz-5]=BigMod(fact[sz-5],mod-2);
    for(int i=sz-6;i>=0;i--)invFact[i]=(invFact[i+1]*(i+1))%mod;
}

ll nCr(int n,int r)
{
    if(n < 0  ||  r < 0  ||  n < r)return 0;
    return (fact[n]*((invFact[r]*invFact[n-r])%mod))%mod;
}

ll DP(int pos,int rem,int val)
{
    if(pos < 0  ||  rem < 0)return 0;
    ll &ans=dp[pos][val];
    if(ans > -1)return ans;
    if(!pos)
    {
        int now=rem+1; ll tmp=1;
        for(int i=val;i;i--)
        {
            int val=cnt[i];
            tmp=(tmp * nCr(now, val))%mod, now -= val;
        }
        return ans=tmp;
    }
    if(!val)return ans=0;
    ans=(nCr(rem,cnt[val]) * DP(pos,rem-cnt[val],val-1))%mod;
    if(cnt[val])ans=(ans + nCr(rem,cnt[val]-1) * DP(pos-2,rem-(cnt[val]-1)+(pos < n ? 1 : 0),val-1))%mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<=n;i++)
        {
            cnt[i]=0;
            for(int j=0;j<=n;j++)dp[i][j]=-1;
        }
        for(int i=1;i<=n;i++)
        {
            int x;cin >> x;
            ++cnt[x];
        }
        cout << DP(n,0,n) << '\n';
    }
    return 0;
}