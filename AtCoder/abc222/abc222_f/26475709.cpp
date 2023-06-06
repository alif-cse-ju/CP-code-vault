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

///Lazy Segment Tree

ll _tree[4*M],lazy[4*M];

void Update(int nodeNum,int start,int end,int l,int r,ll value)
{
    if(lazy[nodeNum] != 0)
    {
        _tree[nodeNum] += lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2] += lazy[nodeNum];
            lazy[nodeNum*2 + 1] += lazy[nodeNum];
        }
        lazy[nodeNum]=0;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        _tree[nodeNum] += value;
        if(start != end)
        {
            lazy[nodeNum*2] += value;
            lazy[nodeNum*2 + 1] += value;
        }
        return;
    }

    int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value);

    _tree[nodeNum]=max(_tree[nodeNum*2] , _tree[nodeNum*2 + 1]);
}

ll Query(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return 0;
    if(lazy[nodeNum] != 0)
    {
        _tree[nodeNum] += lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2] += lazy[nodeNum];
            lazy[nodeNum*2 + 1] += lazy[nodeNum];
        }
        lazy[nodeNum]=0;
    }
    if(start >= l  &&  end <= r)return _tree[nodeNum];

    int mid=(start+end)/2;
    return max(Query(nodeNum*2,start,mid,l,r) , Query(nodeNum*2 + 1,mid+1,end,l,r));
}

///Lazy Segment Tree

int cnt,n,L[M],R[M];
ll ans[M],D[M],dist[M];
vector<pair<int,int>>adj[M];

void DFS1(int x,int p)
{
    L[x]=++cnt;
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)
        {
            dist[y]=dist[x]+z;
            DFS1(y,x);
        }
    }
    R[x]=cnt;
}

void DFS2(int x,int p)
{
    ans[x]=Query(1,1,n,1,n);
    Update(1,1,n,L[x],L[x],D[x]);
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)
        {
            Update(1,1,n,1,n,z);
            Update(1,1,n,L[y],R[y],-2*z);
            Update(1,1,n,L[y],L[y],-D[y]);

            DFS2(y,x);

            Update(1,1,n,1,n,-z);
            Update(1,1,n,L[y],R[y],2*z);
            Update(1,1,n,L[y],L[y],D[y]);
        }
    }
    Update(1,1,n,L[x],L[x],-D[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,x,y,z;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    for(i=1;i<=n;i++)cin >> D[i];
    DFS1(1,0);
    for(i=2;i<=n;i++)Update(1,1,n,L[i],L[i],dist[i]+D[i]);
    DFS2(1,0);
    for(i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}
