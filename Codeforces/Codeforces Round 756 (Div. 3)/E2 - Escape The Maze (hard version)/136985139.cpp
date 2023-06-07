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
const int N=1e6+5;
const int mod=1e9+7;
vector<int>adj[M];
bool ok,visited[M];
int dist1[M],dist2[M];
priority_queue<pair<int,int>>pq;
void Dijkstra()
    while(!pq.empty())
    {
        auto [d,x]=pq.top();
        pq.pop();
        if(visited[x])continue;
        visited[x]=1, d*=(-1);
        for(int y : adj[x])
        {
            if(dist2[y] > d+1)dist2[y]=d+1, pq.emplace(-dist2[y],y);
        }
    }
}
 void DFS(int x,int p)
{
    dist1[x]=dist1[p]+1;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    if((int)adj[x].size() > 1  &&  dist1[x] >= dist2[x])return;
    if(x != 1  &&  (int)adj[x].size() == 1  &&  dist1[x] < dist2[x])ok=1;
}
 int DFS2(int x,int p)
{
    if(dist1[x] >= dist2[x])return 1;
    int ans=0;
    for(int y : adj[x])
    {
        if(p ^ y)ans += DFS2(y,x);
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)visited[i]=0, dist2[i]=1e9, adj[i].clear();
        while(k--)cin >> x, pq.emplace(0,x), dist2[x]=0;
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        Dijkstra();
        ok=0, dist1[0]=-1, DFS(1,0);
        if(ok)cout << "-1\n";
        else cout << DFS2(1,0) << '\n';
    }
    return 0;
}