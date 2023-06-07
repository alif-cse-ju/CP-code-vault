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

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

vector<int>ans;
bool visited[M];
vector<pair<int,int>>adj[M];
priority_queue<pair<int,int>>pq;
int adjS[M],dep[M],par[M],parE[M];

void DFS(int x,int p)
{
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)dep[y]=dep[x]+1, par[y]=x, parE[y]=z, DFS(y,x);
    }
}

void Solve()
{
    ans.clear();
    while(!pq.empty())
    {
        auto [v,x]=pq.top();
        pq.pop();
        if(visited[x])continue;
        int px=par[x];
        if(visited[px]  ||  adjS[px] > 2)
        {
            cout << "-1";
            return;
        }
        if(adjS[px] == 2)
        {
            int y;
            while(!adj[px].empty())
            {
                auto [yy,z]=adj[px].back(); adj[px].pop_back();
                if(yy == x  ||  visited[yy]  ||  yy == par[px])continue;
                else y=yy;
            }
            visited[x]=visited[px]=visited[y]=1;
            if(parE[px])ans.emplace_back(parE[px]), --adjS[par[px]];
        }
        else
        {
            int ppx=par[px];
            if(visited[ppx])
            {
                cout << "-1";
                return;
            }
            visited[x]=visited[px]=visited[ppx]=1;
            if(parE[ppx])ans.emplace_back(parE[ppx]), --adjS[par[ppx]];
        }
    }
    cout << (int)ans.size() << '\n';
    for(int &x : ans)cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)adj[i].clear(), visited[i]=0;
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y,i);
            adj[y].emplace_back(x,i);
        }
        if(n%3)
        {
            cout << "-1\n";
            continue;
        }
        DFS(1,0);
        while(!pq.empty())pq.pop();
        for(int i=1;i<=n;i++)pq.emplace(dep[i],i), adjS[i]=(int)adj[i].size()-(i != 1);
        Solve();
        cout << '\n';
    }
    return 0;
}
