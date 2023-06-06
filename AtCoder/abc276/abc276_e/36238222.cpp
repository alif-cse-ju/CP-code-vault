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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

string s[N];
int h,w,sx,sy;
vector<bool>visited[N];

void DFS(int x,int y,int px,int py)
{
    if(x < 0  ||  y < 0  ||  x >= h  ||  y >= w  ||  s[x][y] == '#')return;
    if(visited[x][y])
    {
        if(x == sx  &&  y == sy)
        {
            cout << "Yes";
            exit(0);
        }
        return;
    }
    visited[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i], yy=y+dy[i];
        if(xx != px  ||  yy != py)DFS(xx,yy,x,y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    for(int i=0;i<h;i++) cin >> s[i], visited[i].resize(w, 0);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(s[i][j] == 'S')sx=i, sy=j;
        }
    }
    DFS(sx,sy,sx,sy);
    cout << "No";
    return 0;
}
