#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

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
const int N=2e6+5;
const int mod=1e9+7;

int timeCnt;
bool visited[M];
vector<int>adj[M];
set<pair<int,int>>bridges;
int lowTimedAdjacentNode[M],parent[M],sz[M],visitedTime[M];

void FindBridges(int node)
{
    if(visitedTime[node] != -1)return;
    visited[node]=true;
    visitedTime[node]=lowTimedAdjacentNode[node]=++timeCnt;
    for(int adjNode : adj[node])
    {
        if(visitedTime[adjNode] == -1)
        {
            parent[adjNode]=node;
            FindBridges(adjNode);
            lowTimedAdjacentNode[node]=min(lowTimedAdjacentNode[node],lowTimedAdjacentNode[adjNode]);
            if(lowTimedAdjacentNode[adjNode] > visitedTime[node])bridges.insert({min(node,adjNode),max(node,adjNode)});
        }
        else if(adjNode != parent[node])lowTimedAdjacentNode[node]=min(lowTimedAdjacentNode[node],visitedTime[adjNode]);
    }
}

int FindParent(int p)
{
    if(parent[p] == p)return p;
    return parent[p]=FindParent(parent[p]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=1; i<=n; i++)parent[i]=visitedTime[i]=lowTimedAdjacentNode[i]=-1;
    for(int i=1;i<=n;i++)
    {
        int x,y; cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])FindBridges(i);
    }
    for(int i=1;i<=n;i++)parent[i]=i, sz[i]=1;
    for(auto [x,y] : bridges)
    {
        int px=FindParent(x), py=FindParent(y);
        if(px != py)
        {
            if(sz[px] >= sz[py])parent[py]=px, sz[px]+=sz[py];
            else parent[px]=py, sz[py]+=sz[px];
        }
    }
    int q;cin >> q;
    while(q--)
    {
        int x,y;cin >> x >> y;
        int px=FindParent(x), py=FindParent(y);
        cout << (px == py ? "Yes\n" : "No\n");
    }
    return 0;
}
