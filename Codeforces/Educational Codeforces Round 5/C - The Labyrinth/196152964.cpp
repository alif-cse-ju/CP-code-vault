#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int mx = 1e3+5;

char grid[mx][mx];
int ans[mx][mx],con,id[mx][mx],m,n,sz[mx*mx];

void DFS(int x,int y)
{
    if(!x  ||  !y  ||  x > n  ||  y > m  ||  grid[x][y] == '*'  ||  id[x][y])return;
    id[x][y]=con, ++sz[con];
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i], yy=y+dy[i];
        DFS(xx,yy);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> grid[i]+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!id[i][j])++con, DFS(i,j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            set<int>st;
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k], y=j+dy[k];
                st.insert(id[x][y]);
            }
            ++ans[i][j];
            for(int it : st)ans[i][j] += sz[it];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(grid[i][j] == '.')cout << '.';
            else cout << ans[i][j]%10;
        }
        cout << '\n';
    }
    return 0;
}
