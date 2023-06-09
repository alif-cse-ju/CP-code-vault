#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int m,n,cnt;
char grid[55][55];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool visited[55][55];
void BFS(int x,int y,char c)
    if(x == 0  ||  y == 0  ||  x > n  ||  y > m  ||  visited[x][y]  ||  grid[x][y] == '#'  ||  (c == 'B'  &&  cnt))return;
    visited[x][y]=true;
    if(grid[x][y] == c)++cnt;
    for(int i=0;i<4;i++)BFS(x+dx[i],y+dy[i],c);
int main()
    FAST();
    int i,j,t,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> grid[i]+1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                visited[i][j]=0;
                if(grid[i][j] == 'B')
                {
                    if(i > 1  &&  grid[i-1][j] == '.')grid[i-1][j]='#';
                    if(i < n  &&  grid[i+1][j] == '.')grid[i+1][j]='#';
                    if(j > 1  &&  grid[i][j-1] == '.')grid[i][j-1]='#';
                    if(j < m  &&  grid[i][j+1] == '.')grid[i][j+1]='#';
                }
                else if(grid[i][j] == 'G')++ans;
            }
        }
        if(!ans)
        {
            cout << "Yes\n";
            continue;
        }
        grid[n][m]='.';
        cnt=0;
        BFS(n,m,'B');
        if(cnt)cout << "No\n";
        else
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)visited[i][j]=0;
            }
            cnt=0;
            BFS(n,m,'G');
            if(cnt == ans)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}