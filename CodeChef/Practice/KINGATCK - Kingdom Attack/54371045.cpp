#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=5e6+5;
const int mod=1e9+7;
int deg[M];
bool visited[M];
vector<int>adj[M],nodes;
void DFS(int x)
{
    if(visited[x])return;
    visited[x]=1, nodes.emplace_back(x);
    for(int y : adj[x])DFS(y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int ans,cnt,i,l,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)adj[i].clear(), deg[i]=visited[i]=0;
        while(m--)
        {
            cin >> x >> y;
            ++deg[x], ++deg[y];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        ans=cnt=0;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                ++cnt, nodes.clear(), DFS(i);
                l=(int)nodes.size(), ok=1;
                for(int it : nodes)ok &= (deg[it] == l-1);
                if(ok)++ans;
            }
        }
        if(cnt == 1)ans=0;
        cout << ans << '\n';
    }
    return 0;
}