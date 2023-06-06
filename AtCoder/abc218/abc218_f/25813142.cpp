#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

set<int>adj[402];
pair<int,int>edge[159602];
map<pair<int,int>,int>edgeId;
priority_queue<pair<int,int>>pq;
int dist[402],par[402],ans[159602];

void Dijkstra()
{
    while(!pq.empty())
    {
        auto [z,x]=pq.top();
        pq.pop();
        z*=-1;
        for(int y : adj[x])
        {
            if(dist[y] > z+1)
            {
                par[y]=x,dist[y]=z+1;
                pq.emplace(-dist[y],y);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y;
        edge[i]={x,y};
        edgeId[{x,y}]=i;
        adj[x].insert(y);
    }
    for(i=1;i<=m;i++)ans[i]=-1;
    for(i=2;i<=n;i++)dist[i]=INT_MAX;
    pq.emplace(0,1),Dijkstra();
    if(dist[n] == INT_MAX)
    {
        for(i=1;i<=m;i++)cout << "-1\n";
    }
    else
    {
        map<pair<int,int>,bool>mark;
        vector<tuple<int,int,int>>path;
        x=n;
        while(x > 1)
        {
            mark[{par[x],x}]=1;
            path.emplace_back(make_tuple(par[x],x,edgeId[{par[x],x}]));
            x=par[x];
        }
        for(i=1;i<=m;i++)
        {
            if(mark.find(edge[i]) == mark.end())ans[i]=dist[n];
        }
        for(auto [x,y,z] : path)
        {
            adj[x].erase(y);
            for(i=2;i<=n;i++)dist[i]=INT_MAX;
            pq.emplace(0,1),Dijkstra();
            if(dist[n] == INT_MAX)dist[n]=-1;
            ans[z]=dist[n];
            adj[x].insert(y);
        }
        for(i=1;i<=m;i++)cout << ans[i] << '\n';
    }
    return 0;
}
