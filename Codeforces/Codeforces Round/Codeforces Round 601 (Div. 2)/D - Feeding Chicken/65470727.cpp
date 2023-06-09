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
     int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    string grid[102];
char final_grid[102][102];
int k,row,col,cnt,mark[65];
 void update(int x,int y)
{
    if(cnt < 27)final_grid[x][y]=(char)(64+cnt);
    else if(cnt < 53)final_grid[x][y]=(char)(70+cnt);
    else final_grid[x][y]=(char)(47+cnt-52);
    if(grid[x][y] == 'R')
    {
        --mark[cnt];
        if(mark[cnt] == 0)cnt=min(k,++cnt);
    }
 }
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,t;
    cin >> t;
    while(t--)
    {
        cin >> row >> col >> k;
        cnt=0;
        for(i=0;i<row;i++)
        {
            cin >> grid[i];
            for(j=0;j<col;j++)
            {
                final_grid[i][j]='#';
                if(grid[i][j] == 'R')++cnt;
            }
        }
        for(i=1;i<=k;i++)mark[i]=0;
        mark[1]+=cnt/k;
        mark[k+1]-=cnt/k;
        mark[1]+=1;
        mark[(cnt%k)+1]-=1;
        for(i=2;i<=k;i++)mark[i]+=mark[i-1];
        cnt=1;
        for(i=0;i<row;i++)
        {
            if(i & 1)
            {
                for(j=col-1;j>=0;j--)update(i,j);
            }
            else for(j=0;j<col;j++)update(i,j);
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                cout << final_grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}