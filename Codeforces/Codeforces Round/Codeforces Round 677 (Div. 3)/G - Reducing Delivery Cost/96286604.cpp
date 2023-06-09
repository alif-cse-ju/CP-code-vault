#include<bits/stdc++.h>
using namespace std;
const int N=1002;
vector<pair<int,int>>adj[N];
int dist[N][N],W[N],X[N],Y[N],dX[N],dY[N];
void Dijkstra(int idx)
    int x,y,z,cost;
    priority_queue<pair<int,int>>pq;
    dist[idx][idx]=0;
    pq.emplace(0,idx);
    while(!pq.empty())
    {
        cost=-pq.top().first;
        x=pq.top().second;
        pq.pop();
        for(pair<int,int>it : adj[x])
        {
            y=it.first,z=it.second;
            if(dist[idx][y] > cost+z)
            {
                dist[idx][y]=cost+z;
                pq.emplace(-cost-z,y);
            }
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,m,n,ans=INT_MAX,cnt;
    cin >> n >> m >> k;
    for(i=1;i<=m;i++)
    {
        cin >> X[i] >> Y[i] >> W[i];
        adj[X[i]].emplace_back(Y[i],W[i]);
        adj[Y[i]].emplace_back(X[i],W[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)dist[i][j]=INT_MAX;
        Dijkstra(i);
    }
    for(i=1;i<=k;i++)cin >> dX[i] >> dY[i];
    for(i=1;i<=m;i++)
    {
        cnt=0;
        for(j=1;j<=k;j++)cnt+=min(dist[dX[j]][dY[j]],min(dist[dX[j]][X[i]]+dist[dY[j]][Y[i]],dist[dX[j]][Y[i]]+dist[dY[j]][X[i]]));
        ans=min(ans,cnt);
    }
    cout << ans;
    return 0;
}