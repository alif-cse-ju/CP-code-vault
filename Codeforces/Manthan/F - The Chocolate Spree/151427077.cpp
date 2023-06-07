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
int par[M];
bool visited[M];
vector<int>adj[M],subTree;
ll a[M],pre[M],preMX[M],suf[M],sufMX[M],sum[M],tmp[M];
void DFS(int x,int p)
    par[x]=p, sum[x]=sum[p]+a[x];
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
void DFS2(int x,int p)
{
    tmp[x]=tmp[p]+a[x], subTree.emplace_back(x);
    for(int y : adj[x])
    {
        if((p ^ y)  &&  !visited[y])DFS2(y,x);
    }
}
 ll DFS3(int x,int p)
{
    ll v=0;
    for(int y : adj[x])
    {
        if(p ^ y)v=max(v, DFS3(y,x));
    }
    return v+a[x];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,mx=0;
    int i,l,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    x=y=0;
    DFS(1,0);
    for(i=1;i<=n;i++)
    {
        if(sum[i] > sum[x])x=i;
    }
    DFS(x,0);
    for(i=1;i<=n;i++)
    {
        if(sum[i] > sum[y])y=i;
    }
    ans=sum[y];
    vector<int>diameterNodes;
    for(i=y;i;i=par[i])diameterNodes.emplace_back(i), visited[i]=1;
    reverse(diameterNodes.begin(),diameterNodes.end());
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            x=y=0;
            subTree.clear();
            DFS2(i,0);
            for(int it : subTree)
            {
                if(tmp[it] > tmp[x])x=it;
            }
            subTree.clear();
            DFS2(x,0);
            for(int it : subTree)
            {
                visited[it]=1;
                if(tmp[it] > tmp[y])y=it;
            }
            mx=max(mx, tmp[y]);
        }
    }
    ans += mx, l=(int)diameterNodes.size();
    for(i=0;i<l;i++)
    {
        if(!i)pre[i]=preMX[i]=a[diameterNodes[i]];
        else
        {
            pre[i]=pre[i-1], mx=0;
            for(int it : adj[diameterNodes[i]])
            {
                if(it == diameterNodes[i-1])continue;
                if(i < l-1  &&  it == diameterNodes[i+1])continue;
                mx=max(mx, DFS3(it,diameterNodes[i]));
            }
            pre[i] += a[diameterNodes[i]], preMX[i]=max(preMX[i-1], pre[i]+mx);
        }
    }
    for(i=l-1;i>=0;i--)
    {
        if(i == l-1)suf[i]=sufMX[i]=a[diameterNodes[i]];
        else
        {
            suf[i]=suf[i+1], mx=0;
            for(int it : adj[diameterNodes[i]])
            {
                if(it == diameterNodes[i+1])continue;
                if(i  &&  it == diameterNodes[i-1])continue;
                mx=max(mx, DFS3(it,diameterNodes[i]));
            }
            suf[i] += a[diameterNodes[i]], sufMX[i]=max(sufMX[i+1], suf[i]+mx);
        }
    }
    for(i=1;i<l;i++)ans=max(ans, preMX[i-1]+sufMX[i]);
    cout << ans;
    return 0;
}