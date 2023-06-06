#include<bits/stdc++.h>

using namespace std;

#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)





int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};




int r,c;
char grid[22][22];
int cost[22][22];
PQ<pair<int,PII>,V<pair<int,PII> >,greater<pair<int,PII> > >pq;

void run_dijkstra()
{
    int i,x,x1,y,y1,bal;
    while(!pq.EM)
    {
        bal=pq.T.FI;
        x=pq.T.SE.FI;
        y=pq.T.SE.SE;
        pq.PP;
        for(i=0;i<4;i++)
        {
            x1=x+dx[i];
            y1=y+dy[i];
            if(x1 > 0  &&  x1 <= r  &&  y1 > 0  &&  y1 <= c  &&  grid[x1][y1] != '#')
            {
                if(cost[x1][y1] > bal+1)
                {
                    cost[x1][y1]=bal+1;
                    pq.PS({bal+1,{x1,y1}});
                }
            }
        }
    }
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,x,y,ans=0;
    cin >> r >> c;
    for(i=1;i<=r;i++)cin >> grid[i]+1;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(grid[i][j] != '#')
            {
                for(x=1;x<=r;x++)
                {
                    for(y=1;y<=c;y++)cost[x][y]=INT_MAX;
                }
                cost[i][j]=0;
                pq.PS({0,{i,j}});
                run_dijkstra();
                for(x=1;x<=r;x++)
                {
                    for(y=1;y<=c;y++)
                    {
                        if(cost[x][y] < INT_MAX)ans=max(ans,cost[x][y]);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
