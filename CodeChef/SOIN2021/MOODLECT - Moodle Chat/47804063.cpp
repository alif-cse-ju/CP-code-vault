#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
ll sum[M];
vector<int>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
{
    inTime[cur]=++timer;
    up[cur][0]=par;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)
        {
            DFS(x,cur);
            sum[cur]=(sum[cur]+sum[x])%mod;
        }
    }
    outTime[cur]=++timer;
}
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
void PreProcess(const int& numberOfNodes,int root)
{
    l=ceil(log2(numberOfNodes));
    DFS(root,root);
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
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)cin >> sum[i];
    PreProcess(n,1);
    cin >> q;
    while(q--)
    {
        cin >> x >> y;
        cout << sum[LCA(x,y)] << '\n';
    }
    return 0;
}