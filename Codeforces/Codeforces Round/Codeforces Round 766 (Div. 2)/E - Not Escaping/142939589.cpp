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
const int N=1e6+5;
const int mod=1e9+7;
int cnt[M];
ll dist[M],X[M];
bool inQueue[M];
vector<int>cols[M];
vector<pair<int,ll>>adj[M];
void Dijkstra(const int& n)
    int x;
    queue<int>q;
    q.emplace(1), inQueue[1]=1;
    while(!q.empty())
    {
        x=q.front(), q.pop();
        inQueue[x]=0;
        for(auto [y,z] : adj[x])
        {
            if(dist[y] > dist[x]+z)
            {
                dist[y]=dist[x]+z;
                if(!inQueue[y])
                {
                    q.emplace(y), inQueue[y]=1;
                    ++cnt[y];
                    if(cnt[y] > n)return;
                }
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll v;
    int a,b,c,d,h,i,j,k,l,m,n,node,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        set<pair<int,int>>distinctPoints;
        vector<tuple<int,int,int,int,int>>ladders;
          for(i=1;i<=n;i++)cin >> X[i], cols[i].clear();
          distinctPoints.insert({1,1});
        distinctPoints.insert({n,m});
        while(k--)
        {
            cin >> a >> b >> c >> d >> h;
            distinctPoints.insert({a,b});
            distinctPoints.insert({c,d});
            ladders.emplace_back(make_tuple(a,b,c,d,h));
        }
          node=0;
        map<pair<int,int>,int>mp;
        for(auto [x,y] : distinctPoints)mp[{x,y}]=++node, cols[x].emplace_back(y);
        for(i=1;i<=node;i++)cnt[i]=inQueue[i]=0, dist[i]=LLONG_MAX, adj[i].clear();
          for(auto [a,b,c,d,h] : ladders)adj[mp[{a,b}]].emplace_back(mp[{c,d}], -h);
          for(i=1;i<=n;i++)
        {
            l=(int)cols[i].size();
            for(j=1;j<l;j++)
            {
                v=1ll * X[i] * (cols[i][j] - cols[i][j-1]);
                adj[mp[{i,cols[i][j]}]].emplace_back(mp[{i,cols[i][j-1]}], v);
                adj[mp[{i,cols[i][j-1]}]].emplace_back(mp[{i,cols[i][j]}], v);
            }
        }
         dist[1]=0;
        Dijkstra(node);
         if(dist[node] == LLONG_MAX)cout << "NO ESCAPE\n";
        else cout << dist[node] << '\n';
    }
    return 0;
}