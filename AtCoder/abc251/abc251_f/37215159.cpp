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

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

int dist[M];
bool visited[M];
vector<int>adj[M];

void DFS(int x)
{
    visited[x]=1;
    for(int &y : adj[x])
    {
        if(!visited[y])cout << x << ' ' << y << '\n', DFS(y);
    }
}

void BFS(int x)
{
    queue<int>q; q.emplace(x);
    while(!q.empty())
    {
        x=q.front(), q.pop();
        for(int &y : adj[x])
        {
            if(dist[y] > dist[x]+1)cout << x << ' ' << y << '\n', dist[y]=dist[x]+1, q.emplace(y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    while(m--)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int i=2;i<=n;i++)dist[i]=INT_MAX;
    DFS(1), BFS(1);
    return 0;
}
