#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int dp[M],lvl[M];
pair<int,int>edges[3*M];
bool mark[3*M],visited[M];
vector<pair<int,int>>adj[M];
void DFS(int x,int p)
    visited[x]=1;
    lvl[x]=lvl[p]+1;
    for(auto [y,i] : adj[x])
    {
        if(p ^ y)
        {
            if(!visited[y])DFS(y,x), mark[i]=1;
        }
    }
 int DFS2(int x,int p)
{
    dp[x]=0;
    for(auto [y,i] : adj[x])
    {
        if(mark[i])
        {
            if(p ^ y)dp[x] += DFS2(y,x);
        }
        else
        {
            if(lvl[y] < lvl[x])++dp[x];
            else --dp[x];
        }
    }
    return dp[x];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y;
        edges[i]={x,y};
        adj[x].emplace_back(y,i);
        adj[y].emplace_back(x,i);
    }
    DFS(1,0);
    x=DFS2(1,0);
    for(i=2;i<=n;i++)
    {
        if(!dp[i])
        {
            cout << "0";
            return 0;
        }
    }
    for(i=1;i<=m;i++)
    {
        auto [x,y]=edges[i];
        if(mark[i])
        {
            if(lvl[x] < lvl[y])cout << x << ' ' << y << '\n';
            else cout << y << ' ' << x << '\n';
        }
        else
        {
            if(lvl[x] > lvl[y])cout << x << ' ' << y << '\n';
            else cout << y << ' ' << x << '\n';
        }
    }
    return 0;
}