#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int dp[M],sz[M];
vector<int>adj[M];
void DFS(int x,int p)
    dp[x]=0, sz[x]=1;
    vector<int>child;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS(y,x), sz[x] += sz[y];
            child.emplace_back(y);
        }
    }
    if((int)child.size() == 1)dp[x]=max(dp[x], sz[child[0]]-1);
    else if((int)child.size() == 2)dp[x]=max({dp[x], sz[child[0]]-1+dp[child[1]], sz[child[1]]-1+dp[child[0]]});
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1,0);
        cout << dp[1] << '\n';
    }
    return 0;
}