#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int m,n;
string grid[N];
void DFS(int x,int y)
    int i,xx,yy,cnt=0;
    for(i=0;i<4;i++)
    {
        xx=x+dx[i], yy=y+dy[i];
        if(xx >= 0  &&  yy >= 0  &&  xx < n  &&  yy < m  &&  grid[xx][yy] != '#'  &&  grid[xx][yy] != '+'  &&  grid[xx][yy] != 'L')++cnt;
    }
    if(grid[x][y] == 'L')cnt=0;
    if(cnt > 1)return;
    if(grid[x][y] == '.')grid[x][y]='+';
    for(i=0;i<4;i++)
    {
        xx=x+dx[i], yy=y+dy[i];
        if(xx >= 0  &&  yy >= 0  &&  xx < n  &&  yy < m  &&  grid[xx][yy] != '#'  &&  grid[xx][yy] != '+'  &&  grid[xx][yy] != 'L')DFS(xx,yy);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,t,x,y;
    cin >> t;
    while(t--)
    {
        x=y=-1;
        cin >> n >> m;
        for(i=0;i<n;i++)
        {
            cin >> grid[i];
            for(j=0;j<m  &&  x == -1;j++)
            {
                if(grid[i][j] == 'L')x=i, y=j;
            }
        }
        DFS(x,y);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)cout << grid[i][j];
            cout << '\n';
        }
    }
    return 0;
}