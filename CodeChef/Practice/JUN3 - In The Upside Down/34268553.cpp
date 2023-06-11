#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int m,n,a[42][42],cost[42][42];
priority_queue<pair<int,PII> >pq;
void Dijkstra()
{
    int i,x,y,z,cx,cy;
    while(!pq.empty())
    {
        z=pq.top().first;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        for(i=0;i<4;i++)
        {
            cx=x+dx[i];
            cy=y+dy[i];
            if(cx < 1  ||  cx > n  ||  cy < 1  ||  cy > m)continue;
            if(a[cx][cy] == 1)
            {
                if(z == 0)continue;
                if(cost[cx][cy] > cost[x][y]+1)
                {
                    cost[cx][cy]=cost[x][y]+1;
                    pq.push({z-1,{cx,cy}});
                }
            }
            else
            {
                if(cost[cx][cy] > cost[x][y]+1)
                {
                    cost[cx][cy]=cost[x][y]+1;
                    pq.push({z,{cx,cy}});
                }
            }
        }
    }
}
int main()
{
    FAST();
    int i,j,k;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cin >> a[i][j],cost[i][j]=INT_MAX;
    }
    cin >> k;
    cost[1][1]=0;
    if(a[1][1] == 1)pq.push({k-1,{1,1}});
    else pq.push({k,{1,1}});
    Dijkstra();
    if(cost[n][m] == INT_MAX)cout << "-1";
    else cout << cost[n][m];
    return 0;
}