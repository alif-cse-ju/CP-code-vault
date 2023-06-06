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
const int N=4e6+5;
const int mod=1e9+7;

int sz[M];
ll ans[M],dp[M];
vector<int>adj[M];

void DFS1(int x,int p)
{
    sz[x]=1;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS1(y,x);
            dp[x]+=dp[y],sz[x]+=sz[y];
        }
    }
    dp[x]+=sz[x]-1;
}

void DFS2(int x,int p)
{
    ans[x]=dp[x];
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            dp[x]-=dp[y]+sz[y];
            sz[x]-=sz[y],sz[y]+=sz[x];
            dp[y]+=dp[x]+sz[x];

            DFS2(y,x);

            dp[y]-=dp[x]+sz[x];
            sz[y]-=sz[x],sz[x]+=sz[y];
            dp[x]+=dp[y]+sz[y];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,y;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS1(1,0);
    DFS2(1,0);
    for(i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}