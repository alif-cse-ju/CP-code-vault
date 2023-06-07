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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int dist[M];
ll ans[M],sumA[M],sumB[M];
ordered_set<pair<ll,int>>ost;
vector<tuple<int,int,int>>adj[M];

void DFS1(int x,int p)
{
    dist[x]=dist[p]+1;
    for(auto [y,a,b] : adj[x])
    {
        if(p ^ y)sumA[y]=a+sumA[x], DFS1(y,x);
    }
}

void DFS2(int x,int p)
{
    for(auto [y,a,b] : adj[x])
    {
        if(p ^ y)
        {
            sumB[y]=b+sumB[x], ost.insert({sumB[y],dist[y]});
            ans[y]=(*ost.find_by_order(ost.order_of_key({sumA[y]+1,0})-1)).second;
            DFS2(y,x), ost.erase(ost.find_by_order(ost.order_of_key({sumB[y],dist[y]})));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dist[0]=-1;
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=2;i<=n;i++)
        {
            int a,b,x;cin >> x >> a >> b;
            adj[i].emplace_back(make_tuple(x,a,b));
            adj[x].emplace_back(make_tuple(i,a,b));
        }
        DFS1(1,0);
        ost.clear(), ost.insert({0,0});
        DFS2(1,0);
        for(int i=2;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
