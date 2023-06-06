#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

const int sz = 2e3+5;

char grid[sz][sz];
bool visited[sz][sz];
int dp[26],dist[sz][sz],m,n;
priority_queue<tuple<int,int,int>>pq;

void Dijkstra()
{
    int i,x1,y1;
    while(!pq.empty())
    {
        auto [z,x,y]=pq.top();
        pq.pop(), z=z*(-1)+1;
        visited[x][y]=1;
        for(i=0;i<4;i++)
        {
            x1=x+dx[i], y1=y+dy[i];
            if(x1  &&  y1  &&  x1 <= n  &&  y1 <= m  &&  grid[x1][y1] != '#')
            {
                if(grid[x1][y1] >= 'a'  &&  grid[x1][y1] <= 'z')
                {
                    if(dist[x1][y1] > min(dp[grid[x1][y1]-'a']+1,z))dist[x1][y1]=min(dp[grid[x1][y1]-'a']+1, z), dp[grid[x1][y1]-'a']=min(dp[grid[x1][y1]-'a'], dist[x1][y1]), pq.emplace(make_tuple(-dist[x1][y1],x1,y1));
                }
                else if(dist[x1][y1] > z)dist[x1][y1]=z, pq.emplace(make_tuple(-dist[x1][y1],x1,y1));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k=25,x1,x2,y1,y2;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> grid[i]+1;
        for(j=1;j<=m;j++)
        {
            dist[i][j]=1e8;
            if(grid[i][j] == 'S')x1=i, y1=j;
            else if(grid[i][j] == 'G')x2=i, y2=j;
        }
    }
    for(i=0;i<26;i++)dp[i]=1e8;
    dist[x1][y1]=0, pq.emplace(make_tuple(0,x1,y1));
    Dijkstra();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)visited[i][j]=0;
    }
    while(k--)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(grid[i][j] >= 'a'  &&  grid[i][j] <= 'z')
                {
                    if(dist[i][j] > dp[grid[i][j]-'a']+1)dist[i][j]=dp[grid[i][j]-'a']+1, visited[i][j]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(visited[i][j]  &&  grid[i][j] >= 'a'  &&  grid[i][j] <= 'z')pq.emplace(make_tuple(-dist[i][j], i, j));
                visited[i][j]=0;
            }
        }
        if(pq.empty())break;
        Dijkstra();
    }
    if(dist[x2][y2] == 1e8)cout << "-1";
    else cout << dist[x2][y2];
    return 0;
}