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
ll ans;
int dist[M];
bool mark[M];
vector<int>adj[M];
bool DFS(int x,int p)
    dist[x]=dist[p]+1;
    bool check=mark[x];
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            if(DFS(y,x))ans += 2, check=1;
        }
    }
    return check;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dist[0]=-1;
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        int X,Y;cin >> X >> Y;
        for(int i=1;i<=n;i++)adj[i].clear(), mark[i]=0;
        while(m--)
        {
            int x;cin >> x;
            mark[x]=1;
        }
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        ans=0, mark[Y]=1;
        bool tmp=DFS(X,0);
        cout << ans-dist[Y] << '\n';
    }
    return 0;
}