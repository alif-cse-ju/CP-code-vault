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
const int N=1e6+5;
const int mod=1e9+7;
///LCA
vector<int>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
    inTime[cur]=++timer;
    up[cur][0]=par;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
    }
    outTime[cur]=++timer;
 bool IsAncestor(int x,int y)
{
    return inTime[x] <= inTime[y]  &&  outTime[x] >= outTime[y];
}
 int LCA(int x,int y)
{
    if(IsAncestor(x,y))return x;
    if(IsAncestor(y,x))return y;
    for(int i=l;i>=0;i--)
    {
        if(!IsAncestor(up[x][i],y))x=up[x][i];
    }
    return up[x][0];
}
 void PreProcess(const int& numberOfNodes)
{
    l=ceil(log2(numberOfNodes));
    DFS(1,1);
}
 ///LCA
 vector<pair<int,int>>adj2[M];
int ans[M],cnt[M],edgeNum[M];
 void DFS2(int x,int p)
{
    for(auto [y,i] : adj2[x])
    {
        if(p ^ y)edgeNum[y]=i, DFS2(y,x), cnt[x] += cnt[y];
    }
    ans[edgeNum[x]]=cnt[x];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,q,x,y;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y), adj[y].emplace_back(x);
        adj2[x].emplace_back(y,i), adj2[y].emplace_back(x,i);
    }
     PreProcess(n);
     cin >> q;
    while(q--)
    {
        cin >> x >> y;
        ++cnt[x], ++cnt[y], cnt[LCA(x,y)]-=2;
    }
     DFS2(1,0);
     for(i=1;i<n;i++)cout << ans[i] << ' ';
    return 0;
}