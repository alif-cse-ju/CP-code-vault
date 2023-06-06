#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int par[M],sz[M];

int FindPar(int x)
{
    if(par[x] == x)return x;
    return par[x]=FindPar(par[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,n,x,y,z;
    cin >> n;
    for(i=1;i<=n;i++)par[i]=i, sz[i]=1;
    vector<tuple<int,int,int>>edges;
    for(i=1;i<n;i++)
    {
        cin >> x >> y >> z;
        edges.emplace_back(make_tuple(z,x,y));
    }
    sort(edges.begin(),edges.end());
    for(auto [z,x,y] : edges)
    {
        x=FindPar(x), y=FindPar(y);
        ans += 1ll*z*sz[x]*sz[y], par[y]=x, sz[x] += sz[y];
    }
    cout << ans;
    return 0;
}