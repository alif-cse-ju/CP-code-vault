#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int>adj[100005];
int parent[100005],dist[100005];
priority_queue<PII,vector<PII>,greater<PII> >pq;

void Dijkstra()
{
    int cost,x;
    while(!pq.empty())
    {
        cost=pq.top().first+1;
        x=pq.top().second;pq.pop();
        for(int y : adj[x])
        {
            if(dist[y] > cost)
            {
                dist[y]=cost;
                parent[y]=x;
                pq.emplace(cost,y);
            }
        }
    }
}

int main()
{
    FAST();
    int i,m,n,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=2;i<=n;i++)dist[i]=INT_MAX;
    pq.emplace(0,1);
    Dijkstra();
    for(i=2;i<=n;i++)
    {
        if(dist[i] == INT_MAX)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for(i=2;i<=n;i++)cout << parent[i] << '\n';
    return 0;
}
