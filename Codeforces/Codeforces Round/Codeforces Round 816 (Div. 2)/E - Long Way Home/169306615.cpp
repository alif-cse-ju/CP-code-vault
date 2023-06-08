#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
const int M=1e5+5;
ll ans[M],dp[2][M];
vector<pair<int,int>>adj[M];
priority_queue<pair<ll,int>>pq;
ll Cost(int i,int j)
    return 1ll*(i-j)*(i-j);
void Dijkstra()
    while(!pq.empty())
    {
        auto [v,x]=pq.top(); pq.pop();
        v *= (-1);
        if(ans[x] < v)continue;
        for(auto [y,z] : adj[x])
        {
            if(ans[y] > v+z)ans[y]=v+z, pq.emplace(-ans[y],y);
        }
    }
void Compute(int cur,int l,int r,int optL,int optR)
{
    if(l > r)return;
    int m=(l+r) >> 1, opt;
    dp[cur][m]=LLONG_MAX;
    for(int i=optL;i<=min(m,optR);i++)
    {
        ll tmp=dp[1-cur][i]+Cost(i,m);
        if(tmp < dp[cur][m])dp[cur][m]=tmp, opt=i;
    }
    Compute(cur,l,m-1,optL,opt), Compute(cur,m+1,r,opt,optR);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,m,n;cin >> n >> m >> k;
    while(m--)
    {
        int x,y,z;cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    for(int i=2;i<=n;i++)ans[i]=1e16;
    pq.emplace(0,1), Dijkstra();
    for(int i=1;i<=n;i++)dp[0][i]=ans[i];
    for(int grpNo=1;grpNo<=k;grpNo++)
    {
        int cur=grpNo%2;
        Compute(cur,1,n,1,n);
        for(int i=1;i<=n;i++)
        {
            if(ans[i] > dp[cur][i])ans[i]=dp[cur][i], pq.emplace(-ans[i],i);
        }
        Dijkstra();
         reverse(dp[1-cur]+1, dp[1-cur]+n+1);
        Compute(cur,1,n,1,n);
        reverse(dp[cur]+1, dp[cur]+n+1);
        for(int i=1;i<=n;i++)
        {
            if(ans[i] > dp[cur][i])ans[i]=dp[cur][i], pq.emplace(-ans[i],i);
        }
        Dijkstra();
        for(int i=1;i<=n;i++)dp[cur][i]=ans[i];
    }
    for(int i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}