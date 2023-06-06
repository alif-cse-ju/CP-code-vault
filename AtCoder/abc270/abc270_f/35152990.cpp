
#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int a[M],b[M],n,par[M],sz[M],x[M],y[M],z[M];

int FindParent(int x)
{
    return par[x]=(par[x] == x ? x : FindParent(par[x]));
}

ll Solve(vector<tuple<int,int,int>>edges)
{
    sort(edges.begin(),edges.end());
    for(int i=1;i<=n+2;i++)par[i]=i, sz[i]=1;
    ll ans=0;
    for(auto [z,x,y] : edges)
    {
        int px=FindParent(x), py=FindParent(y);
        if(px != py)
        {
            ans += z;
            if(sz[px] >= sz[py])par[py]=px, sz[px]+=sz[py];
            else par[px]=py, sz[py]+=sz[px];
        }
    }
    set<int>st;
    for(int i=1;i<=n;i++)st.insert(FindParent(i));
    if((int)st.size() == 1)return ans;
    return LLONG_MAX;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> b[i];
    for(int i=1;i<=m;i++)cin >> x[i] >> y[i] >> z[i];
    ll ans=LLONG_MAX;
    for(int i=0;i<4;i++)
    {
        vector<tuple<int,int,int>>edges;
        if((i >> 0) & 1)
        {
            for(int j=1;j<=n;j++)edges.emplace_back(make_tuple(a[j],j,n+1));
        }
        if((i >> 1) & 1)
        {
            for(int j=1;j<=n;j++)edges.emplace_back(make_tuple(b[j],j,n+2));
        }
        for(int j=1;j<=m;j++)edges.emplace_back(make_tuple(z[j],x[j],y[j]));
        ans=min(ans, Solve(edges));
    }
    cout << ans;
    return 0;
}
