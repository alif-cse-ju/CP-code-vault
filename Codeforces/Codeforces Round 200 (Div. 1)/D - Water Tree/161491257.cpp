#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
///Query type-1
int lazy[4*M],_tree[4*M];
void Update(int nodeNum,int start,int end,int l,int r,int val)
    if(lazy[nodeNum])
    {
        _tree[nodeNum]=lazy[nodeNum];
        if(start != end)lazy[2*nodeNum]=lazy[2*nodeNum+1]=lazy[nodeNum];
        lazy[nodeNum]=0;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        _tree[nodeNum]=val;
        if(start != end)lazy[2*nodeNum]=lazy[2*nodeNum+1]=val;
        return;
    }
    int m=(start+end) >> 1;
    Update(2*nodeNum,start,m,l,r,val);
    Update(2*nodeNum+1,m+1,end,l,r,val);
    _tree[nodeNum]=max(_tree[2*nodeNum], _tree[2*nodeNum+1]);
}
 int Query1(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return INT_MIN;
    if(lazy[nodeNum])
    {
        _tree[nodeNum]=lazy[nodeNum];
        if(start != end)lazy[2*nodeNum]=lazy[2*nodeNum+1]=lazy[nodeNum];
        lazy[nodeNum]=0;
    }
    if(start >= l  &&  end <= r)return _tree[nodeNum];
    int m=(start+end) >> 1;
    return max(Query1(2*nodeNum,start,m,l,r), Query1(2*nodeNum+1,m+1,end,l,r));
}
 ///Query type-1
 ///Query type-2
 int segTree[4*M];
 void Update(int nodeNum,int start,int end,int i,int val)
{
    if(start == end)
    {
        segTree[nodeNum]=val;
        return;
    }
    int m=(start+end) >> 1;
    if(i <= m)Update(2*nodeNum,start,m,i,val);
    else Update(2*nodeNum+1,m+1,end,i,val);
    segTree[nodeNum]=max(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
 int Query2(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query2(2*nodeNum,start,m,l,r);
    else if(l > m)return Query2(2*nodeNum+1,m+1,end,l,r);
    return max(Query2(2*nodeNum,start,m,l,r), Query2(2*nodeNum+1,m+1,end,l,r));
}
 ///Query type-2
 vector<int>adj[M];
int cnt,in[M],out[M];
 void DFS(int x,int p)
{
    in[x]=++cnt;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    out[x]=cnt;
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
    DFS(1,0);
    int q;cin >> q;
    for(int qt=1;qt<=q;qt++)
    {
        int t,i;cin >> t >> i;
        if(t == 1)Update(1,1,n,in[i],out[i],qt);
        else if(t == 2)Update(1,1,n,in[i],qt);
        else cout << (Query1(1,1,n,in[i],in[i]) > Query2(1,1,n,in[i],out[i])) << '\n';
    }
    return 0;
}