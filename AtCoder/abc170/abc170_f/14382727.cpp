#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,j,k,m,n,x,y,z,dx,dy;
    cin >> n >> m >> k;
    int dist[n+5][m+5];
    char grid[n+5][m+5];
    cin >> x >> y >> dx >> dy;
    for(i=1;i<=n;i++)
    {
        cin >> grid[i]+1;
        for(j=1;j<=m;j++)dist[i][j]=INT_MAX;
    }
    priority_queue<pair<int,PII>,vector<pair<int,PII> >,greater<pair<int,PII> > >pq;
    dist[x][y]=0;
    pq.push({0,{x,y}});
    while(!pq.empty())
    {
        z=pq.top().first+1;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        for(i=x-1;i>=x-k;i--)
        {
            if(i == 0  ||  dist[i][y] < z  ||  grid[i][y] == '@')break;
            else
            {
                if(dist[i][y] == z)continue;
                dist[i][y]=z;
                pq.push({z,{i,y}});
            }
        }
        for(i=x+1;i<=x+k;i++)
        {
            if(i > n  ||  dist[i][y] < z  ||  grid[i][y] == '@')break;
            else
            {
                if(dist[i][y] == z)continue;
                dist[i][y]=z;
                pq.push({z,{i,y}});
            }
        }
        for(i=y-1;i>=y-k;i--)
        {
            if(i == 0  ||  dist[x][i] < z  ||  grid[x][i] == '@')break;
            else
            {
                if(dist[x][i] == z)continue;
                dist[x][i]=z;
                pq.push({z,{x,i}});
            }
        }
        for(i=y+1;i<=y+k;i++)
        {
            if(i > m  ||  dist[x][i] < z  ||  grid[x][i] == '@')break;
            else
            {
                if(dist[x][i] == z)continue;
                dist[x][i]=z;
                pq.push({z,{x,i}});
            }
        }
    }
    if(dist[dx][dy] == INT_MAX)cout << "-1";
    else cout << dist[dx][dy];
    return 0;
}
