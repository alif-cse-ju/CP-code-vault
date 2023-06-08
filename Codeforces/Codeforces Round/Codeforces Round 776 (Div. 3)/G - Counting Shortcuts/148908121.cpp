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
int dist[M];
ll dp[M][2];
bool visited[M];
vector<int>adj[M];
priority_queue<pair<int,int>>pq;
void Dijkstra()
    while(!pq.empty())
    {
        auto [v,x]=pq.top();
        pq.pop(), v=v*(-1)+1;
        if(visited[x])continue;
        visited[x]=1;
        for(int y : adj[x])
        {
            if(dist[y] > v)dist[y]=v, pq.emplace(-v,y);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a >> b;
        for(i=1;i<=n;i++)
        {
            adj[i].clear(), visited[i]=0;
            dist[i]=1e9, dp[i][0]=dp[i][1]=0;
        }
        while(m--)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        dist[a]=0, pq.emplace(0,a);
        Dijkstra();
        dp[a][0]=1;
        vector<pair<int,int>>voda;
        for(i=1;i<=n;i++)voda.emplace_back(dist[i],i);
        sort(voda.begin(),voda.end());
        for(auto [v,x] : voda)
        {
            for(int y : adj[x])
            {
                if(dist[y] == v)
                {
                    dp[y][1] += dp[x][0];
                    if(dp[y][1] >= mod)dp[y][1] -= mod;
                }
                else if(dist[y] == v+1)
                {
                    dp[y][0] += dp[x][0];
                    if(dp[y][0] >= mod)dp[y][0] -= mod;
                }
            }
        }
        for(auto [v,x] : voda)
        {
            for(int y : adj[x])
            {
                if(dist[y] == v+1)
                {
                    dp[y][1] += dp[x][1];
                    if(dp[y][1] >= mod)dp[y][1] -= mod;
                }
            }
        }
        cout << (dp[b][0] + dp[b][1]) % mod << '\n';
    }
    return 0;
}