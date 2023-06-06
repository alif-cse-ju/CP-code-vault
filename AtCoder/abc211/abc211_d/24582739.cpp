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

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

ll dp[N];
int dist[N];
bool visited[N];
vector<int>adj[N];
priority_queue<pair<int,int>>pq;

void Dijkstra()
{
    int d,x;
    while(!pq.empty())
    {
        d=-pq.top().first,x=pq.top().second;
        pq.pop();
        if(visited[x])continue;
        visited[x]=1;
        dp[x]%=mod;
        for(int y : adj[x])
        {
            if(dist[y] > d+1)dist[y]=d+1,dp[y]=dp[x],pq.emplace(-d-1,y);
            else if(dist[y] == d+1)dp[y]+=dp[x];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=2;i<=n;i++)dist[i]=INT_MAX;
    dp[1]=1;
    pq.emplace(0,1);
    Dijkstra();
    cout << dp[n];
    return 0;
}