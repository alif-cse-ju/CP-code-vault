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
    bool found;
int ans,row,col;
V<string>grid;
V<string>visited;
 void run_1st_dfs(int x,int y)
{
    if(x == row  ||  y == col  ||  grid[x][y] == '#'  ||  visited[x][y] == '1')
    {
        return;
    }
    if(x == row-1  &&  y == col-1)
    {
        ans++;
        found=true;
        return;
    }
    visited[x][y]='1';
    if(!found)
    {
        run_1st_dfs(x,y+1);
    }
    if(!found)
    {
        run_1st_dfs(x+1,y);
    }
}
 void run_2nd_dfs(int x,int y)
{
    if(x == row  ||  y == col  ||  grid[x][y] == '#'  ||  visited[x][y] == '2')
    {
        return;
    }
    if(visited[x][y] == '1')
    {
        found=true;
        return;
    }
    if(x == row-1  &&  y == col-1)
    {
        ans++;
        found=true;
        return;
    }
    visited[x][y]='1';
    if(!found)
    {
        run_1st_dfs(x+1,y);
    }
    if(!found)
    {
        run_1st_dfs(x,y+1);
    }
}
 int main()
{
    FAST();
     //    freopen("input.txt","r",stdin);
    //    freopen("input.txt","w",stdout);
     int i;
    string s1="",s2;
    cin >> row >> col;
    for(i=0; i<col; i++)
    {
        s1+='0';
    }
    for(i=0; i<row; i++)
    {
        cin >> s2;
        grid.PSB(s2);
        visited.PSB(s1);
    }
    if(row > 1  &&  grid[0][1] == '#'  &&  grid[1][0] == '#')
    {
        cout << 0;
        return 0;
    }
    found=false;
    run_1st_dfs(0,0);
    found=false;
    visited[0][0]='0';
    run_2nd_dfs(0,0);
    cout << ans;
    return 0;
}