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
struct Edge
    int l,r,x,y;
    Edge() {}
    Edge(int _x,int _y,int _l,int _r)
    {
        l=_l, r=_r, x=_x, y=_y;
    }
 edges[M];
vector<int>updates,segTree[4*M];
int ans[M],conComponent,par[M],sz[M];
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
        int px=FindParent(edges[it].x), py=FindParent(edges[it].y);
        if(px != py)
        {
            --conComponent;
            if(sz[px] >= sz[py])sz[px]+=sz[py], par[py]=px, updates.emplace_back(py);
            else sz[py]+=sz[px], par[px]=py, updates.emplace_back(px);
        }
    }
    if(l == r)ans[l]=conComponent;
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
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);
    int n,q;cin >> n >> q;
    map<pair<int,int>,int>mp;
    int edgeCnt=0, queryCnt=0;
    while(q--)
    {
        string s;cin >> s;
        if(s[0] == '?')++queryCnt;
        else
        {
            int xx,yy;cin >> xx >> yy;
            if(xx > yy)swap(xx,yy);
            if(s[0] == '+')mp[{xx,yy}]=++edgeCnt, edges[edgeCnt]=Edge(xx,yy,queryCnt+1,M);
            else edges[mp[{xx,yy}]].r = queryCnt;
        }
    }
    for(int i=1;i<=edgeCnt;i++)
    {
        auto [l,r,x,y]=edges[i];
        if(l > r)continue;
        Insert(1,1,queryCnt,l,r,i);
    }
    conComponent = n;
    for(int i=1;i<=n;i++)par[i]=i, sz[i]=1;
    Solve(1,1,queryCnt);
    for(int i=1;i<=queryCnt;i++)cout << ans[i] << '\n';
    return 0;
}