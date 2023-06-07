#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+5;
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
    int l=1,r=1e9;
    while(l <= r)
    {
        int m=(l+r) >> 1;
        if(Check(m))r=m-1;
        else l=m+1;
    }
    cout << (r+1 > 1e9 ? -1 : r+1);
    return 0;
}