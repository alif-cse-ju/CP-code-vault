#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

bool visited[N];
long long dist[N];
vector<pair<int,pair<int,int>>>adj[N];
priority_queue<pair<long long,int>>pq;

void Dijkstra()
{
    int k,t,x,y;
    long long val;
    while(!pq.empty())
    {
        val=-pq.top().first;
        x=pq.top().second;
        pq.pop();
        if(visited[x])continue;
        visited[x]=1;
        for(auto it : adj[x])
        {
            y=it.first;
            t=it.second.first;
            k=it.second.second;
            if(dist[y] > ((val+k-1)/k)*k+t)
            {
                dist[y]=((val+k-1)/k)*k+t;
                pq.emplace(-dist[y],y);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,i,k,m,n,t,x,y;
    cin >> n >> m >> a >> b;
    while(m--)
    {
        cin >> x >> y >> t >> k;
        adj[x].push_back({y,{t,k}});
        adj[y].push_back({x,{t,k}});
    }
    for(i=1;i<=n;i++)dist[i]=LLONG_MAX;
    dist[a]=0;
    pq.emplace(0,a);
    Dijkstra();
    if(dist[b] == LLONG_MAX)cout << "-1";
    else cout << dist[b];
    return 0;
}
//
