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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

vector<int>adj[M];
int n,LG,dist[M][2],dp[M][20][2];

void DFS(int cur,int par,int id)
{
    dist[cur][id]=dist[par][id]+1;
    dp[cur][0][id]=par;
    for(int i=1;i<=LG;i++)dp[cur][i][id]=dp[dp[cur][i-1][id]][i-1][id];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur,id);
    }
}

void PreCal(int x,int y)
{
    LG=ceil(log2(n));
    dist[x][0]=dist[y][1]=-1;
    DFS(x,x,0), DFS(y,y,1);
}

int FindKth(int node,int k,int id)
{
    for(int i=LG;i>=0;i--)
    {
        if((1 << i) <= k)
        {
            k-=(1 << i);
            node=dp[node][i][id];
        }
    }
    return node;
}

void DFS2(int cur,int par,int id)
{
    dist[cur][id]=dist[par][id]+1;
    for(int x : adj[cur])
    {
        if(x ^ par)DFS2(x,cur,id);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS2(1,0,0);
    int x=0, y=0; dist[0][0]=-1;
    for(int i=1;i<=n;i++)
    {
        if(dist[i][0] > dist[x][0])x=i;
    }
    DFS2(x,0,0);
    for(int i=1;i<=n;i++)
    {
        if(dist[i][0] > dist[y][0])y=i;
    }
    PreCal(x,y);
    int q;cin >> q;
    while(q--)
    {
        int k,x;cin >> x >> k;
        if(dist[x][0] >= k)cout << FindKth(x,k,0) << '\n';
        else if(dist[x][1] >= k)cout << FindKth(x,k,1) << '\n';
        else cout << "-1\n";
    }
    return 0;
}
