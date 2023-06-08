#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
ll dist[M];
priority_queue<pair<ll,int>>pq;
vector<pair<int,int>>adj[M],revAdj[M];
void Dijkstra(int id)
    while(!pq.empty())
    {
        auto [v,x]=pq.top(); pq.pop();
        v *= (-1);
        if(dist[x] < v)continue;
        for(auto [y,z] : (id ? adj[x] : revAdj[x]))
        {
            if(dist[y] > v+z)dist[y]=v+z, pq.emplace(-dist[y],y);
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
        int x,y,z;cin >> x >> y >> z;
        adj[x].emplace_back(y,z), revAdj[y].emplace_back(x,z);
    }
    for(int i=2;i<=n;i++)dist[i]=1e18; pq.emplace(0,1), Dijkstra(1);
    for(int i=1;i<=n;i++)pq.emplace(-dist[i],i); Dijkstra(0);
    for(int i=2;i<=n;i++)cout << (dist[i] == 1e18 ? -1 : dist[i]) << ' ';
    return 0;
}