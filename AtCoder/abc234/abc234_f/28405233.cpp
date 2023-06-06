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

const int M=5e3+5;
const int N=2e6+5;
const int mod=998244353;

int cnt[26];
ll dp[26][M],ways[M][M];

ll Ways(int n,int m)
{
    if(!m)return 0;
    if(!n)return 1;
    ll &ans=ways[n][m];
    if(ans > -1)return ans;
    return ans=(Ways(n,m-1) + Ways(n-1,m))%mod;
}

ll DP(int pos,int rem)
{
    if(pos == 26)return (rem == 0);
    ll &ans=dp[pos][rem];
    if(ans > -1)return ans;
    ans=0;
    for(int i=0;i<=min(cnt[pos],rem);i++)ans=(ans + Ways(i,rem-i+1) * DP(pos+1,rem-i))%mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l;
    ll ans=0;
    string s;
    cin >> s;
    for(char c : s)++cnt[c-'a'];
    memset(dp,-1,sizeof(dp));
    memset(ways,-1,sizeof(ways));
    l=(int)s.size();
    for(i=l;i;i--)
    {
        ans += DP(0,i);
        if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}
