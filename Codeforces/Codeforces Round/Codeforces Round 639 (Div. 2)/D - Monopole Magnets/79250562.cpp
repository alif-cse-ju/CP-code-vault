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
    int m,n;
char s[1005][1005];
bool visited[1005][1005];
 void runDFS(int x,int y)
{
    if(x < 1  ||  x > n  ||  y < 1  ||  y > m  ||  s[x][y] == '.'  ||  visited[x][y])return;
    visited[x][y]=true;
    for(int i=0;i<4;i++)runDFS(x+dx[i],y+dy[i]);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,cnt;
    bool row=false,col=false;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> s[i]+1;
    for(i=1;i<=n;i++)
    {
        cnt=(s[i][1] == '#');
        for(j=2;j<=m;j++)cnt+=(s[i][j-1] == '.'  &&  s[i][j] == '#');
        row |= (cnt == 0);
        if(cnt > 1)
        {
            cout << "-1";
            return 0;
        }
    }
    for(i=1;i<=m;i++)
    {
        cnt=(s[1][i] == '#');
        for(j=2;j<=n;j++)cnt+=(s[j-1][i] == '.'  &&  s[j][i] == '#');
        col |= (cnt == 0);
        if(cnt > 1)
        {
            cout << "-1";
            return 0;
        }
    }
    if((row  &&  !col)  ||  (!row  &&  col))
    {
        cout << "-1";
        return 0;
    }
    cnt=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i][j] == '#'  &&  !visited[i][j])
            {
                ++cnt;
                runDFS(i,j);
            }
        }
    }
    cout << cnt;
    return 0;
}