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

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

ll dist[M];
queue<int>Q;
int par[M],sz[M];
bool loop[M],visited[M];
vector<pair<int,int>>adj[M];

int FindParent(int x)
{
    if(par[x] == x)return x;
    return par[x]=FindParent(par[x]);
}

void BFS()
{
    while(!Q.empty())
    {
        int x=Q.front(); Q.pop();
        for(auto [y,z] : adj[x])
        {
            if(dist[y] > dist[x]+z)
            {
                if(visited[y])
                {
                    while(!Q.empty())Q.pop();
                    loop[FindParent(y)]=1;
                    return;
                }
                visited[y]=1, dist[y]=dist[x]+z, Q.emplace(y);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,q;cin >> n >> m >> q;
    for(int i=1;i<=n;i++)dist[i]=LLONG_MAX, par[i]=i, sz[i]=1;
    while(m--)
    {
        int x,y,z;cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,-z);
        int px=FindParent(x), py=FindParent(y);
        if(px != py)
        {
            if(sz[px] >= sz[py])par[py]=px, sz[px]+=sz[py];
            else par[px]=py, sz[py]+=sz[px];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]  &&  !loop[FindParent(i)])dist[i]=0, Q.emplace(i), BFS();
    }
    while(q--)
    {
        int x,y;cin >> x >> y;
        if(FindParent(x) != FindParent(y))cout << "nan\n";
        else if(loop[FindParent(x)])cout << "inf\n";
        else cout << dist[y]-dist[x] << '\n';
    }
    return 0;
}