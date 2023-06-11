#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
vector<int>adj[M];
int lg,timer,dist[M],inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
{
    inTime[cur]=++timer;
    up[cur][0]=par, dist[cur]=dist[par]+1;
    for(int i=1;i<=lg;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
    }
    outTime[cur]=++timer;
}
void PreProcess(const int& numberOfNodes,const int& root)
{
    lg=ceil(log2(numberOfNodes)), dist[root]=-1;
    DFS(root,root);
}
bool IsAncestor(int x,int y)
{
    return inTime[x] <= inTime[y]  &&  outTime[x] >= outTime[y];
}
int LCA(int x,int y)
{
    if(IsAncestor(x,y))return x;
    if(IsAncestor(y,x))return y;
    for(int i=lg;i>=0;i--)
    {
        if(!IsAncestor(up[x][i],y))x=up[x][i];
    }
    return up[x][0];
}
int FindKth(int node,int k)
{
    for(int i=lg;i>=0;i--)
    {
        if((1 << i) <= k)
        {
            k-=(1 << i);
            node=up[node][i];
        }
    }
    return node;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    PreProcess(n,1);
    int q;cin >> q;
    while(q--)
    {
        int rt,x,y;cin >> rt >> x >> y;
        int lca=LCA(x,y);
        if(!(inTime[lca] < inTime[rt]  &&  outTime[rt] < outTime[lca]))cout << lca << '\n';
        else
        {
            int ans,l=0,r=dist[x];
            while(l <= r)
            {
                    int m=(l+r) >> 1;
                    int kth=FindKth(x,m);
                    if(inTime[kth] <= inTime[rt]  &&  outTime[rt] <= outTime[kth])ans=kth, r=m-1;
                    else l=m+1;
            }
            if(ans == lca)
            {
                l=0,r=dist[y]-dist[lca];
                while(l <= r)
                {
                    int m=(l+r) >> 1;
                    int kth=FindKth(y,m);
                    if(inTime[kth] <= inTime[rt]  &&  outTime[rt] <= outTime[kth])ans=kth, r=m-1;
                    else l=m+1;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}