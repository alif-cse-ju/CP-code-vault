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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
struct Basis
    vector<long long> a;
    void insert(long long x)
    {
        for(auto &i: a) x = min(x, x ^ i);
        if(!x) return;
        for(auto &i: a) if((i ^ x) < i) i ^= x;
        a.emplace_back(x);
        sort(a.begin(), a.end());
    }
    bool can(long long x)
    {
        for(auto &i: a) x = min(x, x ^ i);
        return !x;
    }
    long long maxxor(long long x = 0)
    {
        for (auto &i: a) x = max(x, x ^ i);
        return x;
    }
    long long minxor(long long x = 0)
    {
        for (auto &i: a) x = min(x, x ^ i);
        return x;
    }
} XOR;
 int xr[M];
bool visited[M];
vector<pair<int,int>>adj[M];
 void DFS(int x)
{
    visited[x]=1;
    for(auto [y,z] : adj[x])
    {
        if(visited[y])XOR.insert(xr[x] ^ xr[y] ^ z);
        else xr[y]=xr[x] ^ z, DFS(y);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    while(m--)
    {
        int x,y,z;cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    DFS(1);
    cout << XOR.minxor(xr[n]);
    return 0;
}