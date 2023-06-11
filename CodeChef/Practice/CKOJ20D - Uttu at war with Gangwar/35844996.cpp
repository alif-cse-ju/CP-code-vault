#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int xr,a[200002];
vector<int>adj[200002];
void DFS(int cur,int par,int deg)
{
    if(deg & 1)xr ^= a[cur];
    for(int it : adj[cur])
    {
        if(it != par)DFS(it,cur,deg+1);
    }
}
int main()
{
    FAST();
    int i,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0,0);
    if(xr)cout << "First";
    else cout << "Second";
    return 0;
}