#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
vector<int>adj[M];
int n,par[M],sz[M];
ll ans[M],fact[M],invFact[M];
long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
void PreCal()
{
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1] * i) % mod;
    invFact[M-1]=BigMod(fact[M-1],mod-2);
    for(int i=M-2;i>=0;i--)invFact[i]=(invFact[i+1] * (i+1)) % mod;
}
void DFS(int x,int p)
{
    par[x]=p, sz[x]=1;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x), sz[x]+=sz[y];
    }
}
int GetCentroid(int x)
{
    bool flag=1;
    while(flag)
    {
        flag=0;
        for(int y : adj[x])
        {
            if(par[x] ^ y)
            {
                if(sz[y]+sz[y] > n)
                {
                    x=y, flag=1;
                    break;
                }
            }
        }
    }
    for(int y : adj[x])
    {
        if(par[x] ^ y)
        {
            if(sz[y]+sz[y] == n)return max(x,y);
        }
    }
    return x;
}
int Get2ndMax(int x)
{
    int mx=0;
    for(int y : adj[x])mx=max(mx, sz[y]);
    int z=0;
    for(int y : adj[x])
    {
        if(sz[y] == mx)z=max(y, z);
    }
    return z;
}
void DFS2(int x,int p)
{
    ans[x]=sz[x]=1;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS2(y,x), sz[x] += sz[y];
            ans[x]=(ans[x] * ans[y]) % mod;
            ans[x]=(ans[x] * invFact[sz[y]]) % mod;
        }
    }
    ans[x]=(ans[x] * fact[sz[x] - 1]) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        int k;cin >> n >> k;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1,0);
        n=GetCentroid(1);
        if(k > 1)DFS(n,0), n=Get2ndMax(n);
        DFS2(n,0);
        cout << n << ' ' << ans[n] << '\n';
    }
    return 0;
}