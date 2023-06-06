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

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int dp[M][2];
bool ache[M];
vector<pair<int,int>>adj[M];
priority_queue<tuple<int,int,int>>pq;

void Dijkstra()
{
    while(!pq.empty())
    {
        auto [d,x,s]=pq.top(); pq.pop();
        d=-d;
        if(dp[x][s] < d)continue;
        for(auto [y,z] : adj[x])
        {
            if(!s)
            {
                if(z  &&  dp[y][0] > d+1)dp[y][0]=d+1, pq.emplace(make_tuple(-d-1,y,0));
                else if(!z  &&  ache[x]  &&  dp[y][1] > d+1)dp[y][1]=d+1, pq.emplace(make_tuple(-d-1,y,1));
            }
            else
            {
                if(!z  &&  dp[y][1] > d+1)dp[y][1]=d+1, pq.emplace(make_tuple(-d-1,y,1));
                else if(z  &&  ache[x]  &&  dp[y][0] > d+1)dp[y][0]=d+1, pq.emplace(make_tuple(-d-1,y,0));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,m,n;cin >> n >> m >> k;
    while(m--)
    {
        int x,y,z;cin >> x >> y >> z;
        adj[x].emplace_back(y,z), adj[y].emplace_back(x,z);
    }
    while(k--)
    {
        int x;cin >> x, ache[x]=1;
    }
    for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=N;
    dp[1][0]=0, pq.emplace(make_tuple(0,1,0)), Dijkstra();
    int ans=min(dp[n][0], dp[n][1]);
    if(ans == N)ans=-1;
    cout << ans;
    return 0;
}
