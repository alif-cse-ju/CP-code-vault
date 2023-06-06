#include<bits/stdc++.h>

using namespace std;

const int N=1e3;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int dist[N+2][N+2];
char grid[N+2][N+2];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,x,x1,x2,y,y1,y2,z;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    for(i=1;i<=n;i++)
    {
        cin >> grid[i]+1;
        for(j=1;j<=m;j++)dist[i][j]=INT_MAX;
    }
    dist[x1][y1]=0;
    pq.push({0,{x1,y1}});
    while(!pq.empty())
    {
        z=pq.top().first;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        for(i=0;i<4;i++)
        {
            x1=x+dx[i];
            y1=y+dy[i];
            if(x1 > 0  &&  x1 <= n  &&  y1 > 0  &&  y1 <=m  &&  grid[x1][y1] == '.'  &&  dist[x1][y1] > z)
            {
                dist[x1][y1]=z;
                pq.push({z,{x1,y1}});
            }
        }
        ++z;
        for(i=x-2;i<=x+2;i++)
        {
            for(j=y-2;j<=y+2;j++)
            {
                if(i > 0  &&  i <= n  &&  j > 0  &&  j <=m  &&  grid[i][j] == '.'  &&  dist[i][j] > z)
                {
                    dist[i][j]=z;
                    pq.push({z,{i,j}});
                }
            }
        }
    }
    if(dist[x2][y2] == INT_MAX)cout << "-1";
    else cout << dist[x2][y2];
    return 0;
}