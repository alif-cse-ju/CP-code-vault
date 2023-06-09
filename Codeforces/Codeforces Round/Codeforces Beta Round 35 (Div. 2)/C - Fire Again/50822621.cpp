#include<bits/stdc++.h>
using namespace std;
int time_needed[2005][2005];
int m,n,k;
vector<int>x_axis;
vector<int>y_axis;
int x_ax[]= {-1,1,0,0};
int y_ax[]= {0,0,-1,1};
queue<pair<int,int> >q;
void run_bfs()
    int i,j,x,y,x1,y1,t1;
    for(i=0; i<k; i++)
    {
        q.push({x_axis[i],y_axis[i]});
        time_needed[x_axis[i]][y_axis[i]]=0;
        while(!q.empty())
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(j=0; j<4; j++)
            {
                x1=x+x_ax[j];
                y1=y+y_ax[j];
                t1=time_needed[x][y]+1;
                if(x1>0 && y1>0 && x1<=n && y1<=m && t1<time_needed[x1][y1])
                {
                    time_needed[x1][y1]=t1;
                    q.push({x1,y1});
                }
            }
        }
    }
}
 int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&m);
    int i,j,x,y;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            time_needed[i][j]=INT_MAX;
        }
    }
    scanf("%d",&k);
    for(i=0; i<k; i++)
    {
        scanf("%d %d",&x,&y);
        x_axis.push_back(x);
        y_axis.push_back(y);
    }
    run_bfs();
    int max_ans=0,indexx=1,indexy=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(time_needed[i][j] > max_ans)
            {
                max_ans=time_needed[i][j];
                indexx=i;
                indexy=j;
            }
        }
    }
    printf("%d %d\n",indexx,indexy);
    return 0;
}