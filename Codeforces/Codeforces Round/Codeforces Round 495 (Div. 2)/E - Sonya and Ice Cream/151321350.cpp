#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int N=2e6+5;
const int mod=998244353;
bool visited[M];
int distAlada[M];
int dist[M][2],par[M][2];
vector<pair<int,int>>adj[M];
void DFS(int x,int p,bool id)
    par[x][id]=p;
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)dist[y][id]=dist[x][id]+z, DFS(y,x,id);
    }
void DFS2(int x)
{
    visited[x]=1;
    for(auto [y,z] : adj[x])
    {
        if(!visited[y])distAlada[y]=distAlada[x]+z, DFS2(y);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0,a,b,i,k,mx=0,n,x,y,z;
    cin >> n >> k;
    if(n == 1)
    {
        cout << "0";
        return 0;
    }
    for(i=1;i<n;i++)
    {
        cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    DFS(1,0,0);
    a=b=0;
    for(i=1;i<=n;i++)
    {
        if(dist[i][0] > dist[a][0])a=i;
    }
    dist[a][0]=0, DFS(a,0,0);
    for(i=1;i<=n;i++)
    {
        if(dist[i][0] > dist[b][0])b=i;
    }
    dist[b][1]=0, DFS(b,0,1);
    vector<int>nodesDiameter;
    for(i=b;i;i=par[i][0])nodesDiameter.emplace_back(i), visited[i]=1;
    reverse(nodesDiameter.begin(),nodesDiameter.end());
    for(int it : nodesDiameter)DFS2(it);
    for(i=1;i<=n;i++)mx=max(mx, distAlada[i]);
    if(k < (int)nodesDiameter.size())
    {
        ans=INT_MAX;
        for(i=k-1;i<(int)nodesDiameter.size();i++)ans=min(ans, max(dist[nodesDiameter[i-k+1]][0], dist[nodesDiameter[i]][1]));
    }
    ans=max(ans, mx);
    cout << ans;
    return 0;
}