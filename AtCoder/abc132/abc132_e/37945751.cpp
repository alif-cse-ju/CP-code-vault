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

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int dist[M][3];
vector<int>adj[M];
priority_queue<tuple<int,int,int>>pq;

void Dijkstra()
{
    while(!pq.empty())
    {
        auto [d,x,p]=pq.top(); pq.pop();
        d *= -1;
        if(dist[x][p] != d)continue;
        ++d, p=(p == 2 ? 0 : p+1);
        for(int &y : adj[x])
        {
            if(dist[y][p] > d)dist[y][p]=d, pq.emplace(make_tuple(-d,y,p));
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
    }
    for(int i=1;i<=n;i++)dist[i][0]=dist[i][1]=dist[i][2]=INT_MAX;
    int s,t;cin >> s >> t;
    dist[s][0]=0, pq.emplace(make_tuple(0,s,0)), Dijkstra();
    if(dist[t][0] == INT_MAX)cout << "-1";
    else cout << dist[t][0]/3;
    return 0;
}
