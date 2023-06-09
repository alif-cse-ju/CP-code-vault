#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int n,m,x_of_s,y_of_s;
int x_of_e,y_of_e;
int visited[1005][1005][4][4];
queue<int>q;
bool flag=0;
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
void make_ans()
    int x,y,dir,cost,i,x1,y1,dir1,cost1;
    while(!q.empty() && flag==0)
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        dir=q.front();
        q.pop();
        cost=q.front();
        q.pop();
        for(i=0; i<4 && flag == 0; i++)
        {
            x1=x+dx[i];
            y1=y+dy[i];
            dir1=i;
            if(x1>0 && y1>0 && x1<=n && y1<=m && grid[x1][y1]!='*')
            {
                if(dir != dir1)
                {
                    cost1=cost+1;
                }
                else
                {
                    cost1=cost;
                }
                if(cost1<3 && visited[x1][y1][dir1][cost1]==-1)
                {
                    visited[x1][y1][dir1][cost1]=1;
                    if(x1==x_of_e && y1==y_of_e)
                    {
                        flag=1;
                        break;
                    }
                    q.push(x1);
                    q.push(y1);
                    q.push(dir1);
                    q.push(cost1);
                }
            }
        }
    }
    if(visited[x_of_e][y_of_e][dir1][cost1] < 3 && visited[x_of_e][y_of_e][dir1][cost1]>-1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
 int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%s",grid[i]+1);
        for(j=1; j<=m; j++)
        {
            if(grid[i][j] == 'S')
            {
                x_of_s=i;
                y_of_s=j;
            }
            else if(grid[i][j] == 'T')
            {
                x_of_e=i;
                y_of_e=j;
            }
        }
    }
     memset(visited,-1,sizeof(visited));
     for(i=0; i<4; i++)
    {
        int x1=x_of_s+dx[i];
        int y1=y_of_s+dy[i];
        if(x1>0 && y1>0 && x1<=n && y1<=m && grid[x1][y1]!='*')
        {
            visited[x_of_s][y_of_s][i][0]=0;
            q.push(x1);
            q.push(y1);
            q.push(i);
            q.push(0);
        }
    }
    make_ans();
    return 0;
}