#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
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

ordered_set<pair<int,int>>ost;

///Calculation
struct query
{
    int l,r,kk,id;
}q[M];
int l,r,k,a[M],ans[M],val[M];

bool Compare(query &x,query &y)
{
    int a=x.l/k,b=y.l/k;
    if(a == b)return x.r < y.r;
    return a < b;
}

void Add(int x)
{
    ost.insert({val[x],x});
}

void Reduce(int x)
{
    ost.erase({val[x],x});
}
///Calculation

vector<int>adj[M];
int in[M],out[M],_timer;

void DFS(int x,int p)
{
    in[x]=++_timer, val[in[x]-1]=a[x];
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    out[x]=_timer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,n,x,y;
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        --x, --y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(0,0);
    k=sqrt(m);
    for(i=0;i<m;i++)
    {
        cin >> x >> l, --x;
        q[i].l=in[x]-1, q[i].r=out[x]-1;
        q[i].id=i, q[i].kk=out[x]-in[x]-l+1;
    }
    sort(q,q+m,Compare);
    l=0,r=-1;
    for(i=0;i<m;i++)
    {
        while(l > q[i].l)Add(--l);
        while(r < q[i].r)Add(++r);
        while(l < q[i].l)Reduce(l++);
        while(r > q[i].r)Reduce(r--);
        auto [v,idx]=*(ost.find_by_order(q[i].kk));
        ans[q[i].id]=v;
    }
    for(i=0;i<m;i++)cout << ans[i] << '\n';
    return 0;
}
