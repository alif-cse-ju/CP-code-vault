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
const int M=1e3+5;
const int N=2e5+5;
const int mod=1e9+7;
vector<int>adj[M];
int cnt,dist[M][M],dpth[M],id[M];
priority_queue<pair<int,int>>pq[M];
void DFS(int x,int p)
    id[x]=cnt;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
void BFS(int i,int x,int p)
    dist[i][x]=dist[i][p]+1;
    for(int y : adj[x])
    {
        if(p ^ y)BFS(i,y,x);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!id[i])
        {
            ++cnt;
            DFS(i,0);
        }
    }
    for(i=1;i<=n;i++)
    {
        dist[i][0]=-1;
        BFS(i,i,0);
        for(j=1,x=0;j<=n;j++)x=max(x,dist[i][j]);
        pq[id[i]].emplace(-x,i);
        dpth[id[i]]=max(dpth[id[i]],x);
    }
    vector<pair<int,int>>v;
    for(i=1;i<=cnt;i++)v.emplace_back(-dpth[i],pq[i].top().second);
    sort(v.begin(),v.end());
    for(i=1;i<(int)v.size();i++)
    {
        adj[v[0].second].emplace_back(v[i].second);
        adj[v[i].second].emplace_back(v[0].second);
    }
    BFS(1,1,0);
    x=1;
    for(i=2;i<=n;i++)
    {
        if(dist[1][i] > dist[1][x])x=i;
    }
    BFS(x,x,0);
    y=0;
    for(i=1;i<=n;i++)y=max(y,dist[x][i]);
    cout << y << '\n';
    for(i=1;i<(int)v.size();i++)cout << v[0].second << ' ' << v[i].second << '\n';
    return 0;
}