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

const int M=1e4+5;
const int N=2e6+5;
const int mod=998244353;

string s;
int l,must;
ll dp[M][1 << 10][2],pw[M],sum[M][1 << 10][2];

void PreCal()
{
    pw[0]=1;
    for(int i=1;i<M;i++)pw[i]=(pw[i-1]*10)%mod;
}

ll DP(int id,int mask,bool small)
{
    if(id == l)return ((mask & must) == must);
    ll &ans=dp[id][mask][small];
    if(ans > -1)return ans;
    ans=0;
    ll ways, &cur=sum[id][mask][small];
    if(small)
    {
        for(int i=0;i<10;i++)
        {
            ways = DP(id+1, ((i | (__builtin_popcount(mask) > 0)) ? (mask | (1 << i)) : 0),1);

            cur = (cur + ((((i * pw[l-id-1])%mod) * ways)%mod) + sum[id+1][((i | (__builtin_popcount(mask) > 0)) ? (mask | (1 << i)) : 0)][1]) % mod;

            ans += ways;
            if(ans >= mod)ans -= mod;
        }
    }
    else
    {
        for(int i=0;i<s[id]-'0';i++)
        {
            ways = DP(id+1, ((i | (__builtin_popcount(mask) > 0)) ? (mask | (1 << i)) : 0),1);

            cur = (cur + ((((i * pw[l-id-1])%mod) * ways)%mod) + sum[id+1][((i | (__builtin_popcount(mask) > 0)) ? (mask | (1 << i)) : 0)][1]) % mod;

            ans += ways;
            if(ans >= mod)ans -= mod;
        }

        {
            ways = DP(id+1, (((s[id]-'0') | (__builtin_popcount(mask) > 0)) ? (mask | (1 << (s[id]-'0'))) : 0),0);

            cur = (cur + (((((s[id]-'0') * pw[l-id-1])%mod) * ways)%mod) + sum[id+1][(((s[id]-'0') | (__builtin_popcount(mask) > 0)) ? (mask | (1 << (s[id]-'0'))) : 0)][0]) % mod;

            ans += ways;
            if(ans >= mod)ans -= mod;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,x;
    cin >> s >> m;
    while(m--)cin >> x, must |= (1 << x);
    l=(int)s.size();
    PreCal();
    memset(dp,-1,sizeof(dp));
    ll tmp=DP(0,0,0);
    cout << sum[0][0][0];
    return 0;
}
