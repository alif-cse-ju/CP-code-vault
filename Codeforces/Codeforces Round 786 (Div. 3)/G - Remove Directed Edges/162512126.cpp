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
vector<int>adj[M];
int dp[M],in[M],out[M];
int DP(int x)
    if(dp[x] != -1)return dp[x];
    if(in[x] > 1  &&  out[x] > 1)
    {
        dp[x]=1;
        for(int y : adj[x])dp[x]=max(dp[x], DP(y)+1);
    }
    else if(in[x] > 1)dp[x]=1;
    else dp[x]=-M;
    return dp[x];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)dp[i]=-1;
    while(m--)
    {
        int x,y;cin >> x >> y;
        ++in[y], ++out[x];
        adj[x].emplace_back(y);
    }
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        if(out[i] > 1)
        {
            for(int y : adj[i])ans=max(ans, DP(y) + 1);
        }
    }
    cout << ans;
    return 0;
}