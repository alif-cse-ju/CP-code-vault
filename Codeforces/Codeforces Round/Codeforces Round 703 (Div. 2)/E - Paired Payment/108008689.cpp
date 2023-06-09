#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
bool visited[N][55];
long long cost[N][55];
vector<pair<int,int>>adj[N];
priority_queue<pair<long long,pair<int,int>>>pq;
void Dijkstra()
    int x,y;
    long long val;
    while(!pq.empty())
    {
        val=-pq.top().first;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        if(visited[x][y])continue;
        visited[x][y]=1;
        for(auto it : adj[x])
        {
            if(!y)
            {
                if(cost[it.first][it.second] > val)
                {
                    cost[it.first][it.second]=val;
                    pq.push({-val,{it.first,it.second}});
                }
            }
            else
            {
                if(cost[it.first][0] > val+(y+it.second)*(y+it.second))
                {
                    cost[it.first][0]=val+(y+it.second)*(y+it.second);
                    pq.push({-cost[it.first][0],{it.first,0}});
                }
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,x,y,z;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<51;j++)cost[i][j]=LLONG_MAX;
    }
    cost[1][0]=0;
    pq.push({0,{1,0}});
    Dijkstra();
    for(i=1;i<=n;i++)
    {
        if(cost[i][0] == LLONG_MAX)cout << "-1 ";
        else cout << cost[i][0] << ' ';
    }
    return 0;
}
//