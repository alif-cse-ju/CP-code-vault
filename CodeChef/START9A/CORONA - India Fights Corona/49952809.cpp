#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
ll dp[M];
bool visited[M];
vector<pair<int,int>>adj[M];
priority_queue<pair<ll,int>>pq;
void Dijkstra()
{
    int x;
    ll val;
    while(!pq.empty())
    {
        val=-pq.top().first;
        x=pq.top().second;
        pq.pop();
        if(visited[x])continue;
        visited[x]=1;
        for(auto [y,z] : adj[x])
        {
            if(dp[y] > val+z)
            {
                dp[y]=val+z;
                pq.emplace(-dp[y],y);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,m,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i=1;i<=n;i++)
        {
            dp[i]=1e18;
            visited[i]=0;
            adj[i].clear();
        }
        for(i=1;i<=k;i++)
        {
            cin >> x >> y;
            dp[x]=y;
            pq.emplace(-y,x);
        }
        while(m--)
        {
            cin >> x >> y >> z;
            adj[x].emplace_back(y,z);
            adj[y].emplace_back(x,z);
        }
        Dijkstra();
        for(i=1;i<=n;i++)cout << dp[i] << ' ';
        cout << '\n';
    }
    return 0;
}