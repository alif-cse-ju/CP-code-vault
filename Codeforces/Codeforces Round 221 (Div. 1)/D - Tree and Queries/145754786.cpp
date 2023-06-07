#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
vector<int>adj[M];
int clr[M],modClr[M],in[M],out[M],timer_;
void DFS(int x,int p)
    in[x]=++timer_, modClr[in[x]-1]=clr[x];
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    out[x]=timer_;
int sum[M];
void Update(int i,int v)
    while(i < M)sum[i] += v, i += (i & -i);
int Query(int i)
    int ans=0;
    while(i)ans += sum[i], i -= (i & -i);
    return ans;
struct query
    int l,r,id,val;
[M];
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