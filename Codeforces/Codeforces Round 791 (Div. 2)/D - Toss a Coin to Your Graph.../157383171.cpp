#pragma GCC optimize("Ofast")
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
ll k;
bool cycle;
bool visited[M];
vector<int>adj[M];
int a[M],dist[M],n;
void DFS(int x,const int& v)
    dist[x]=1;
    visited[x]=1;
    for(int y : adj[x])
    {
        if(cycle)return;
        if(a[y] > v)continue;
        if(!dist[y])
        {
            DFS(y,v);
            dist[x]=max(dist[x], dist[y]+1);
        }
        else
        {
            if(visited[y])cycle=1;
            else dist[x]=max(dist[x], dist[y]+1);
        }
    }
    visited[x]=0;
}
 bool Check(const int& v)
{
    cycle=0;
    for(int i=1;i<=n;i++)dist[i]=visited[i]=0;
    for(int i=1;i<=n  &&  !cycle;i++)
    {
        if(a[i] <= v  &&  !dist[i])DFS(i,v);
    }
    if(cycle)return 1;
    for(int i=1;i<=n;i++)
    {
        if(dist[i] >= k)return 1;
    }
    return 0;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;cin >> n >> m >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    while(m--)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
    }
    int l=0,r=1e9;
    while(l <= r)
    {
        int m=(l+r) >> 1;
        if(Check(m))r=m-1;
        else l=m+1;
    }
    if(r+1 > 1e9)cout << "-1";
    else cout << r+1;
    return 0;
}