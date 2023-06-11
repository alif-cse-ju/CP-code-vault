#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
vector<int>adj[M];
ordered_set<ll>ost;
ll a[M],ans[M],deg[M];
vector<tuple<int,ll,int>>queries[M];
void DFS1(int x,int p)
{
    for(int y : adj[x])
    {
        if(p ^ y)deg[x] += a[y], deg[y] += a[x], DFS1(y,x);
    }
}
void DFS2(int x,int p)
{
    ost.insert(deg[x]);
    for(int y : adj[x])
    {
        if(p ^ y)DFS2(y,x);
    }
    int l = (int)ost.size();
    for(auto [t,k,i] : queries[x])
    {
        if(l < t)ans[i]=-1;
        else
        {
            ll v = *(ost.find_by_order(l - t));
            if(!v)ans[i]=-1;
            else
            {
                ll L=1, R=sqrt((1e18) / v) * 2;
                while(L <= R)
                {
                    ll m=(L+R) >> 1;
                    if(((m*(m+1))/2)*v >= k)R=m-1;
                    else L=m+1;
                }
                ans[i]=R+1;
            }
        }
    }
    ost.erase(ost.find_by_order(ost.order_of_key(deg[x])));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i], deg[i] = a[i];
        adj[i].clear(), queries[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y), adj[y].emplace_back(x);
    }
    int q;cin >> q;
    for(int i=1;i<=q;i++)
    {
        int x,t; ll k; cin >> x >> t >> k;
        queries[x].emplace_back(make_tuple(t,k,i));
    }
    DFS1(1,0), DFS2(1,0);
    for(int i=1;i<=q;i++)cout << ans[i] << '\n';
    return 0;
}