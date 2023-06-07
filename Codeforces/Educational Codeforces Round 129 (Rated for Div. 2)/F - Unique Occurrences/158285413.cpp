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
const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;
vector<int>nodes[M];
vector<pair<int,int>>adj[M];
int dp[M],last[M],parent[M],rootHas[M],subSize[M];
void DFS(int x,int p)
    subSize[x]=1;
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)DFS(y,x), subSize[x] += subSize[y];
    }
    dp[x]=subSize[x];
void DFS2(int x,int p)
{
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)
        {
            int l=last[z];
            last[z]=y, parent[y]=l, DFS2(y,x);
            nodes[z].emplace_back(y);
            if(!l)rootHas[z] -= subSize[y];
            else dp[l] -= subSize[y];
            last[z]=l;
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<n;i++)
    {
        int x,y,z;cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    DFS(1,0), DFS2(1,0);
    for(int i=1;i<=n;i++)rootHas[i]+=n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int y : nodes[i])
        {
            int x=parent[y];
            if(x)ans += 1ll*dp[x]*dp[y];
            else ans += 1ll*rootHas[i]*dp[y];
        }
    }
    cout << ans;
    return 0;
}