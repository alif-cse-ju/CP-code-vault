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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll fenwickTree[M];
int m,n,reversePos[M];
void FenwickUpdate(int i,ll v)
    while(i <= n)fenwickTree[i]+=v, i+=(i & -i);
ll FenwickQuery(int i)
    ll ans=0;
    while(i)ans+=fenwickTree[i], i-=(i & -i);
    return ans;
 ll lazy[4*M];
tuple<ll,int,int>node[4*M];
vector<pair<int,int>>val[M];
 void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        node[nodeNum]=make_tuple(1e16,n+5,m+5);
        if(!val[l].empty())node[nodeNum]=make_tuple(val[l].back().first, reversePos[l], val[l].back().second);
        return;
    }
     int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid), Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=min(node[2*nodeNum], node[2*nodeNum+1]);
}
 void Update(int nodeNum,int start,int end,int l,int r,ll value)
{
    if(lazy[nodeNum] != 0)
    {
        auto &[x,y,z]=node[nodeNum]; x += lazy[nodeNum];
        if(start != end)lazy[nodeNum*2]+=lazy[nodeNum], lazy[nodeNum*2 + 1]+=lazy[nodeNum];
        lazy[nodeNum]=0;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        auto &[x,y,z]=node[nodeNum]; x += value;
        if(start != end) lazy[nodeNum*2]+=value, lazy[nodeNum*2 + 1]+=value;
        return;
    }
     int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value), Update(nodeNum*2 + 1,mid+1,end,l,r,value);
    node[nodeNum]=min(node[2*nodeNum], node[2*nodeNum+1]);
}
 void Delete(int nodeNum,int start,int end,int pos)
{
    if(start == end)
    {
        val[start].pop_back();
        node[nodeNum]=make_tuple(1e16,n+5,m+5);
        if(!val[start].empty())node[nodeNum]=make_tuple(val[start].back().first + FenwickQuery(start), reversePos[start], val[start].back().second);
        return;
    }
    int m=(start+end) >> 1;
    if(pos <= m)Delete(2*nodeNum,start,m,pos);
    else Delete(2*nodeNum+1,m+1,end,pos);
    node[nodeNum]=min(node[2*nodeNum], node[2*nodeNum+1]);
}
 tuple<ll,int,int>SegmentTreeQuery(int nodeNum,int start,int end,int l,int r)
{
    if(lazy[nodeNum] != 0)
    {
        auto &[x,y,z]=node[nodeNum]; x += lazy[nodeNum];
        if(start != end)lazy[nodeNum*2]+=lazy[nodeNum], lazy[nodeNum*2 + 1]+=lazy[nodeNum];
        lazy[nodeNum]=0;
    }
    if(start >= l  &&  end <= r)return node[nodeNum];
    int mid=(start+end)/2;
    if(r <= mid)return SegmentTreeQuery(nodeNum*2,start,mid,l,r);
    if(l > mid)return SegmentTreeQuery(nodeNum*2 + 1,mid+1,end,l,r);
    return min(SegmentTreeQuery(nodeNum*2,start,mid,l,r), SegmentTreeQuery(nodeNum*2 + 1,mid+1,end,l,r));
}
 vector<int>adj[M];
int curPos,depth[M],headofCurrentChain[M],heavyChild[M],in[M],out[M],parent[M],pos[M];
 int DFS(int cur)
{
    int childSize,size=1,maxChildSize=0;
    for(int x : adj[cur])
    {
        if(x ^ parent[cur])
        {
            parent[x]=cur;
            depth[x]=depth[cur]+1;
            childSize=DFS(x);
            size+=childSize;
            if(childSize > maxChildSize)
            {
                heavyChild[cur]=x;
                maxChildSize=childSize;
            }
        }
    }
    return size;
}
 void Decompose(int cur,int headNode)
{
    pos[cur]=++curPos, in[cur]=curPos, reversePos[curPos]=cur;
    headofCurrentChain[cur]=headNode;
    if(heavyChild[cur])Decompose(heavyChild[cur],headNode);
    for(int x : adj[cur])
    {
        if(x != parent[cur]  &&  x != heavyChild[cur])Decompose(x,x);
    }
    out[cur]=curPos;
}
 void HeavyLightDecomposition()
{
    DFS(1);
    curPos=0;
    Decompose(1,1);
}
 tuple<ll,int,int>HLDQuery(int x,int y)
{
    tuple<ll,int,int>ans=make_tuple(1e16,n+5,m+5), curVal;
    while(headofCurrentChain[x] != headofCurrentChain[y])
    {
        if(depth[headofCurrentChain[x]] > depth[headofCurrentChain[y]])swap(x,y);
        curVal=SegmentTreeQuery(1,1,n,pos[headofCurrentChain[y]],pos[y]);
        ans=min(ans, curVal);
        y=parent[headofCurrentChain[y]];
    }
    if(depth[x] > depth[y])swap(x,y);
    curVal=SegmentTreeQuery(1,1,n,pos[x],pos[y]);
    return min(ans, curVal);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;cin >> n >> m >> q;
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y), adj[y].emplace_back(x);
    }
    HeavyLightDecomposition();
    for(int i=1;i<=m;i++)
    {
        int x;cin >> x;
        val[pos[x]].emplace_back(i,i);
    }
    for(int i=1;i<=n;i++)reverse(val[i].begin(),val[i].end());
    Build(1,1,n);
    while(q--)
    {
        int t;cin >> t;
        if(t == 2)
        {
            int x,v;cin >> x >> v;
            Update(1,1,n,in[x],out[x],v);
            FenwickUpdate(in[x],v), FenwickUpdate(out[x]+1,-v);
        }
        else
        {
            vector<int>ans;
            int k,x,y;cin >> x >> y >> k;
            while(k--)
            {
                auto [v,nodeNum,id]=HLDQuery(x,y);
                if(id > m)break;
                ans.emplace_back(id);
                Update(1,1,n,pos[nodeNum],pos[nodeNum],0), Delete(1,1,n,pos[nodeNum]);
            }
            cout << (int)ans.size();
            for(int &it : ans)cout << ' ' << it;
            cout << '\n';
        }
    }
    return 0;
}