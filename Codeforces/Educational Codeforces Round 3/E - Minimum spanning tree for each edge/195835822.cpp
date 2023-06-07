#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

ll ans[M];
bool mark[M];
int par[M],sz[M];
vector<pair<int,int>>adj[M];
tuple<int,int,int,int>edges[M];

/// HLD

int node[4*M],val[M];

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        node[nodeNum]=val[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=max(node[2*nodeNum], node[2*nodeNum+1]);
}

int SegmentTreeQuery(int nodeNum,int start,int end,int l,int r)
{
    if(l <= start  &&  r >= end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return SegmentTreeQuery(nodeNum*2,start,mid,l,r);
    if(mid < l)return SegmentTreeQuery(nodeNum*2+1,mid+1,end,l,r);
    return max(SegmentTreeQuery(nodeNum*2,start,mid,l,mid), SegmentTreeQuery(nodeNum*2+1,mid+1,end,mid+1,r));
}

int curPos,depth[M],headofCurrentChain[M],heavyChild[M],n,parent[M],pos[M],v[M];

int DFS(int cur)
{
    int childSize,size=1,maxChildSize=0;
    for(auto [x,y] : adj[cur])
    {
        if(x ^ parent[cur])
        {
            parent[x]=cur, v[x]=y;
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
    pos[cur]=++curPos;
    headofCurrentChain[cur]=headNode;
    if(heavyChild[cur])Decompose(heavyChild[cur],headNode);
    for(auto [x,y] : adj[cur])
    {
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
    int ans=0,curVal;
    while(headofCurrentChain[x] != headofCurrentChain[y])
    {
        if(depth[headofCurrentChain[x]] > depth[headofCurrentChain[y]])swap(x,y);
        ans=max(ans, SegmentTreeQuery(1,1,n,pos[headofCurrentChain[y]],pos[y]));
        y=parent[headofCurrentChain[y]];
    }
    if(depth[x] > depth[y])swap(x,y);
    if(pos[x] < pos[y])ans=max(ans, SegmentTreeQuery(1,1,n,pos[x]+1,pos[y]));
    return ans;
}


/// DSU
int FindPar(int p)
{
    if(par[p] == p)return p;
    return par[p]=FindPar(par[p]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;cin >> n >> m;
    for(int i=1;i<=n;i++)par[i]=i, sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;cin >> x >> y >> z;
        edges[i]=make_tuple(z,x,y,i);
    }
    ll tot=0;
    sort(edges+1,edges+m+1);
    for(int i=1;i<=m;i++)
    {
        auto [z,x,y,j]=edges[i];
        int px=FindPar(x), py=FindPar(y);
        if(px == py)continue;
        mark[j]=1, tot+=z;
        if(sz[px] >= sz[py])par[py]=px, sz[px]+=sz[py];
        else par[px]=py, sz[py]+=sz[px];
        adj[x].emplace_back(y,z), adj[y].emplace_back(x,z);
    }
    HeavyLightDecomposition();
    for(int i=1;i<=n;i++)val[pos[i]]=v[i];
    Build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        auto [z,x,y,j]=edges[i];
        if(mark[j])ans[j]=tot;
        else ans[j]=tot-HLDQuery(x,y)+z;
    }
    for(int i=1;i<=m;i++)cout << ans[i] << '\n';
    return 0;
}
