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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
ll sum[M];
vector<int>adj[M];
int l,n,timer,a[M],inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
    up[cur][0]=par;
    inTime[cur]=++timer;
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
 void PreProcess()
{
    l=ceil(log2(n));
    DFS(1,1);
}
 void Update(int i,int v)
{
    while(i <= (n << 1))sum[i] += v, i += (i & -i);
}
 ll Query(int i)
{
    ll ans=0;
    while(i)ans += sum[i], i -= (i & -i);
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,lca,op,q,x,y;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    PreProcess();
    for(i=1;i<=n;i++)Update(inTime[i],abs(a[i])), Update(outTime[i],-abs(a[i]));
    while(q--)
    {
        cin >> op >> x >> y;
        if(op == 1)
        {
            Update(inTime[x],abs(y)-abs(a[x]));
            Update(outTime[x],-(abs(y)-abs(a[x])));
            a[x]=y;
        }
        else
        {
            lca=LCA(x,y);
            ans=2ll*(Query(inTime[x])-Query(inTime[lca]));
            ans+=2ll*(Query(inTime[y])-Query(inTime[lca]));
            ans += 2*abs(a[lca])-abs(a[x])-abs(a[y]);
            cout << ans << '\n';
        }
    }
    return 0;
}