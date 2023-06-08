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
const int M=1e5+5;
const int N=2e6+5;
const int mod=998244353;
vector<int>adj[M];
int clr[M],modClr[M],in[M],out[M],timer_;
void DFS(int x,int p)
    in[x]=++timer_, modClr[in[x]-1]=clr[x];
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    out[x]=timer_;
///BIT
int sum[M];
 void Update(int i,int v)
{
    while(i < M)sum[i] += v, i += (i & -i);
}
 int Query(int i)
{
    int ans=0;
    while(i)ans += sum[i], i -= (i & -i);
    return ans;
}
 ///BIT
 ///Calculation
 struct query
{
    int l,r,id,val;
}q[M];
int l,r,k,ans[M],cnt[M];
 bool Compare(query &x,query &y)
{
    int a=x.l/k,b=y.l/k;
    if(a == b)return x.r < y.r;
    return a < b;
}
 void Add(int x)
{
    x=modClr[x];
    if(cnt[x])Update(cnt[x],-1);
    ++cnt[x], Update(cnt[x],1);
}
 void Reduce(int x)
{
    x=modClr[x];
    Update(cnt[x],-1), --cnt[x];
    if(cnt[x])Update(cnt[x],1);
}
 ///Calculation
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> clr[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    k=sqrt(m), DFS(1,0);
    for(i=0;i<m;i++)
    {
        cin >> x >> y;
        q[i].l=in[x]-1, q[i].r=out[x]-1;
        q[i].id=i, q[i].val=y;
    }
    sort(q,q+m,Compare);
    l=0,r=-1;
    for(i=0;i<m;i++)
    {
        while(l > q[i].l)Add(--l);
        while(r < q[i].r)Add(++r);
        while(l < q[i].l)Reduce(l++);
        while(r > q[i].r)Reduce(r--);
        ans[q[i].id]=Query(M-5)-Query(q[i].val-1);
    }
    for(i=0;i<m;i++)cout << ans[i] << '\n';
    return 0;
}