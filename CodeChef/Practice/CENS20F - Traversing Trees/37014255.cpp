#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int parent[N+2];
long long val[N+2];
vector<int>adj[N+2];
bool visited[N+2][2];
void FindParent(int cur,int par)
{
    parent[cur]=par;
    for(int x : adj[cur])
    {
        if(x ^ par)FindParent(x,cur);
    }
}
void DFS(int cur,int par,int parity,int src)
{
    if(cur != src  &&  !parity)
    {
        val[src]+=val[cur];
        val[cur]=0;
    }
    if(!visited[cur][parity])
    {
        for(int x : adj[cur])
        {
            if(x ^ par)DFS(x,cur,parity ^ 1,src);
        }
    }
    visited[cur][parity]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,q,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i=1;i<=n;i++)
        {
            cin >> val[i];
            adj[i].clear();
            visited[i][0]=visited[i][1]=0;
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        FindParent(1,0);
        while(q--)
        {
            cin >> x;
            if(!visited[x][0])DFS(x,parent[x],0,x);
            visited[x][0]=1;
        }
        for(i=1;i<=n;i++)cout << val[i] << ' ';
        cout << '\n';
    }
    return 0;
}