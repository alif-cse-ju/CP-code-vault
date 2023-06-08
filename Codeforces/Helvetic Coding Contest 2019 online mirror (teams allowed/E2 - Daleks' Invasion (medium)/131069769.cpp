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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
/********************Segment Tree********************/
int n,val[M],node[4*M];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=val[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
}
 void Update(int nodeNum,int start,int end,int pos,int x)
{
    if(start == end)
    {
        node[nodeNum]=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
}
 int SegmentTreeQuery(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  l > r)return INT_MIN;
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return SegmentTreeQuery(nodeNum*2,start,mid,l,r);
    if(mid < l)return SegmentTreeQuery(nodeNum*2+1,mid+1,end,l,r);
    return max(SegmentTreeQuery(nodeNum*2,start,mid,l,mid),SegmentTreeQuery(nodeNum*2+1,mid+1,end,mid+1,r));
}
 /********************Segment Tree********************/
 int a[M];
 /********************Heavy Light Decomposition********************/
 vector<pair<int,int>>adj[M];
int curPos,depth[M],headofCurrentChain[M],heavyChild[M],parent[M],pos[M];
 int DFS(int cur)
{
    int x,y,childSize,size=1,maxChildSize=0;
    for(auto it : adj[cur])
    {
        x=it.first;
        y=it.second;
        if(x ^ parent[cur])
        {
            a[x]=y;
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
    int x;
    pos[cur]=++curPos;
    headofCurrentChain[cur]=headNode;
    if(heavyChild[cur])Decompose(heavyChild[cur],headNode);
    for(auto it : adj[cur])
    {
        x=it.first;
        if(x != parent[cur]  &&  x != heavyChild[cur])Decompose(x,x);
    }
}
 void HeavyLightDecomposition()
{
    DFS(1);
    curPos=0;
    Decompose(1,1);
}
 int HLDQuery(int x,int y)
{
    int ans=INT_MIN,curVal;
    while(headofCurrentChain[x] != headofCurrentChain[y])
    {
        if(depth[headofCurrentChain[x]] > depth[headofCurrentChain[y]])swap(x,y);
        curVal=SegmentTreeQuery(1,1,n,pos[headofCurrentChain[y]],pos[y]);
        ans=max(ans,curVal);
        y=parent[headofCurrentChain[y]];
    }
    if(depth[x] > depth[y])swap(x,y);
    if(pos[x] < pos[y])curVal=SegmentTreeQuery(1,1,n,pos[x]+1,pos[y]);
    return max(ans,curVal);
}
 /********************Heavy Light Decomposition********************/
 bool mark[N];
int p[M],ans[N];
tuple<int,int,int,int>edges[N];
 int FindParent(int i)
{
    if(p[i] == i)return i;
    return p[i]=FindParent(p[i]);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,px,py,x,y,z;
    cin >> n >> m;
    for(i=1;i<=n;i++)p[i]=i;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        edges[i]=make_tuple(z,x,y,i);
    }
    sort(edges+1,edges+m+1);
    for(j=1;j<=m;j++)
    {
        auto [z,x,y,i]=edges[j];
        px=FindParent(x);
        py=FindParent(y);
        if(px != py)
        {
            p[py]=px, mark[i]=1;
            adj[x].emplace_back(y,z);
            adj[y].emplace_back(x,z);
        }
    }
    HeavyLightDecomposition();
    for(i=1;i<=n;i++)val[pos[i]]=a[i];
    Build(1,1,n);
    for(j=1;j<=m;j++)
    {
        auto [z,x,y,i]=edges[j];
        if(mark[i])continue;
        ans[i]=HLDQuery(x,y);
    }
    for(i=1;i<=m;i++)
    {
        if(!mark[i])cout << ans[i] << '\n';
    }
    return 0;
}