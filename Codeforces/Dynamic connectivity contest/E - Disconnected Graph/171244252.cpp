#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;
pair<int,int>edges[M];
int ans[M],conComponent,par[M],sz[M];
vector<int>updates,segTree[4*M],pos[M];
void Insert(int nodeNum,int start,int end,int l,int r,int v)
    if(start >= l  &&  end <= r)
    {
        segTree[nodeNum].emplace_back(v);
        return;
    }
    int m=(start+end) >> 1;
    if(r <= m)Insert(2*nodeNum,start,m,l,r,v);
    else if(l > m)Insert(2*nodeNum+1,m+1,end,l,r,v);
    else Insert(2*nodeNum,start,m,l,r,v), Insert(2*nodeNum+1,m+1,end,l,r,v);
}
 int FindParent(int x)
{
    if(par[x] == x)return x;
    return FindParent(par[x]);
}
 void Solve(int nodeNum, int l, int r)
{
    if(l > r)return;
    int curSize=(int)updates.size();
    for(int it : segTree[nodeNum])
    {
        int px=FindParent(edges[it].first), py=FindParent(edges[it].second);
        if(px != py)
        {
            --conComponent;
            if(sz[px] >= sz[py])sz[px]+=sz[py], par[py]=px, updates.emplace_back(py);
            else sz[py]+=sz[px], par[px]=py, updates.emplace_back(px);
        }
    }
    if(l == r)ans[l]=(conComponent == 1);
    else
    {
        int m=(l+r) >> 1;
        Solve(2*nodeNum,l,m), Solve(2*nodeNum+1,m+1,r);
    }
    while((int)updates.size() > curSize)
    {
        ++conComponent;
        int py=updates.back(); updates.pop_back();
        sz[par[py]]-=sz[py], par[py]=py;
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("disconnected.in","r",stdin);
    freopen("disconnected.out","w",stdout);
    int m,n;cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin >> x >> y;
        edges[i]={x,y};
    }
    int q;cin >> q;
    for(int i=1;i<=q;i++)
    {
        int k;cin >> k;
        while(k--)
        {
            int x;cin >> x;
            pos[x].emplace_back(i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        int l=1, r;
        for(int it : pos[i])
        {
            r=it;
            if(l < r)Insert(1,1,q,l,r-1,i);
            l=it+1;
        }
        if(l <= q)Insert(1,1,q,l,q,i);
    }
    conComponent = n;
    for(int i=1;i<=n;i++)par[i]=i, sz[i]=1;
    Solve(1,1,q);
    for(int i=1;i<=q;i++)cout << (ans[i] ? "Connected" : "Disconnected") << '\n';
    return 0;
}