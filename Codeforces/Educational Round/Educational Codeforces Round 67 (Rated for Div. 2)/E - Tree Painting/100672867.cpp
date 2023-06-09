#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int sz[N];
vector<int>adj[N];
long long ans,dp[N];
void DFS1(int x,int par)
    sz[x]=1;
    for(int y : adj[x])
    {
        if(y ^ par)
        {
            DFS1(y,x);
            sz[x]+=sz[y];
            dp[x]+=dp[y];
        }
    }
    dp[x]+=sz[x];
void DFS2(int x,int par)
    for(int y : adj[x])
    {
        if(y ^ par)
        {
            dp[x]-=(dp[y]+sz[y]);
            sz[x]-=sz[y];
            dp[y]+=dp[x]+sz[x];
            sz[y]+=sz[x];
            ans=max(ans,dp[y]);
            DFS2(y,x);
            dp[y]-=(dp[x]+sz[x]);
            sz[y]-=sz[x];
            dp[x]+=dp[y]+sz[y];
            sz[x]+=sz[y];
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,y;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS1(1,1);
    ans=dp[1];
    DFS2(1,1);
    cout << ans;
    return 0;
}