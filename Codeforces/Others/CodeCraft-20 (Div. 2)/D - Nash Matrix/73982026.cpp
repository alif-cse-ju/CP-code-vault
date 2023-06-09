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
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    char grid[1002][1002];
PII points[1002][1002];
 void runBFS(int x,int y,int bossX,int bossY,char c)
{
    if(points[x][y].FI != bossX  ||  points[x][y].SE != bossY  ||  grid[x][y] != '*')return;
    grid[x][y]=c;
    runBFS(x-1,y,bossX,bossY,'D');
    runBFS(x+1,y,bossX,bossY,'U');
    runBFS(x,y-1,bossX,bossY,'R');
    runBFS(x,y+1,bossX,bossY,'L');
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            grid[i][j]='*';
            cin >> points[i][j].FI;
            cin >> points[i][j].SE;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(points[i][j].FI == -1)
            {
                if(grid[i][j] == '*')
                {
                    if(points[i+1][j].FI == -1)
                    {
                        grid[i][j]='D';
                        if(grid[i+1][j] == '*')grid[i+1][j]='U';
                    }
                    else if(points[i-1][j].FI == -1)
                    {
                        grid[i][j]='U';
                        if(grid[i-1][j] == '*')grid[i-1][j]='D';
                    }
                    else if(points[i][j+1].FI == -1)
                    {
                        grid[i][j]='R';
                        if(grid[i][j+1] == '*')grid[i][j+1]='L';
                    }
                    else if(points[i][j-1].FI == -1)
                    {
                        grid[i][j]='L';
                        if(grid[i][j-1] == '*')grid[i][j-1]='R';
                    }
                    else
                    {
                        cout << "INVALID";
                        return 0;
                    }
                }
            }
            else if(points[i][j].FI == i  &&  points[i][j].SE == j)
            {
                grid[i][j]='X';
                runBFS(i-1,j,i,j,'D');
                runBFS(i+1,j,i,j,'U');
                runBFS(i,j-1,i,j,'R');
                runBFS(i,j+1,i,j,'L');
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(grid[i][j] == '*')
            {
                cout << "INVALID";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    for(i=1;i<=n;i++)cout << grid[i]+1 << '\n';
    return 0;
}