#include<bits/stdc++.h>

using namespace std;

const int M=5e2+5;

bool visited[M][M];
int c,r,a[M][M],b[M][M],dist[M][M];
priority_queue<pair<int,pair<int,int>>>pq;

void Dijkstra()
{
    int i,x,xx,y,yy,cost;
    while(!pq.empty())
    {
        cost=-pq.top().first;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        if(x == r  &&  y == c)return;
        //if(visited[x][y])continue;
        visited[x][y]=1;
        if(y < c)
        {
            xx=x,yy=y+1;
            if(dist[xx][yy] > cost+a[x][y])
            {
                dist[xx][yy]=cost+a[x][y];
                pq.push({-dist[xx][yy],{xx,yy}});
            }
        }
        if(y > 1)
        {
            xx=x,yy=y-1;
            if(dist[xx][yy] > cost+a[xx][yy])
            {
                dist[xx][yy]=cost+a[xx][yy];
                pq.push({-dist[xx][yy],{xx,yy}});
            }
        }
        if(x < r)
        {
            xx=x+1,yy=y;
            if(dist[xx][yy] > cost+b[x][y])
            {
                dist[xx][yy]=cost+b[x][y];
                pq.push({-dist[xx][yy],{xx,yy}});
            }
        }
        for(i=1;i<x;i++)
        {
            xx=x-i,yy=y;
            if(dist[xx][yy] > cost+i+1)
            {
                dist[xx][yy]=cost+i+1;
                pq.push({-dist[xx][yy],{xx,yy}});
            }
            //else break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j;
    cin >> r >> c;
    for(i=1;i<=r;i++)
    {
        dist[i][c]=INT_MAX;
        for(j=1;j<c;j++)cin >> a[i][j],dist[i][j]=INT_MAX;
    }
    for(i=1;i<r;i++)
    {
        for(j=1;j<=c;j++)cin >> b[i][j];
    }
    dist[1][1]=0;
    pq.push({0,{1,1}});
    Dijkstra();
    cout << dist[r][c];
    return 0;
}