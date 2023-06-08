#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
bool visited[N];
int ans[N][2],dist[N];
vector<int>adj[N],revAdj[N];
priority_queue<pair<int,int>>pq1;
priority_queue<pair<pair<int,int>,bool>>pq2;
void Dijkstra()
    int x,cost;
    while(!pq1.empty())
    {
        cost=-pq1.top().first;
        x=pq1.top().second;
        pq1.pop();
        if(visited[x])continue;
        visited[x]=1;
        for(int y : adj[x])
        {
            if(dist[y] > cost+1)
            {
                dist[y]=cost+1;
                pq1.emplace(-dist[y],y);
            }
        }
    }
void Solve()
    int x,cost;
    bool flag;
    while(!pq2.empty())
    {
        cost=-pq2.top().first.first;
        x=pq2.top().first.second;
        flag=pq2.top().second;
        pq2.pop();
        for(int y : revAdj[x])
        {
            if(!flag)
            {
                if(dist[y] < dist[x])
                {
                    if(ans[y][0] > cost)
                    {
                        ans[y][0]=cost;
                        pq2.push({{-cost,y},0});
                    }
                }
                else
                {
                    if(ans[y][1] > cost)
                    {
                        ans[y][1]=cost;
                        pq2.push({{-cost,y},1});
                    }
                }
            }
            else
            {
                if(dist[y] < dist[x])
                {
                    if(ans[y][1] > cost)
                    {
                        ans[y][1]=cost;
                        pq2.push({{-cost,y},1});
                    }
                }
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
            adj[i].clear();
            revAdj[i].clear();
            ans[i][0]=ans[i][1]=dist[i]=INT_MAX;
        }
        while(m--)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            revAdj[y].emplace_back(x);
        }
        ans[1][0]=ans[1][1]=dist[1]=0;
        pq1.emplace(0,1);
        Dijkstra();
        for(i=1;i<=n;i++)pq2.push({{-dist[i],i},0});
        Solve();
        for(i=1;i<=n;i++)cout << min(dist[i],min(ans[i][0],ans[i][1])) << ' ';
        cout << '\n';
    }
    return 0;
}