#include<bits/stdc++.h>
using namespace std;
int dep[102];
vector<int>adj[102];
void DFS(int cur,int par)
{
    dep[cur]=dep[par]+1;
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n=0,t,x,y;
    cin >> t;
    while(t--)
    {
        for(i=1;i<=n;i++)adj[i].clear();
        cin >> n;
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1,0);
        for(i=1;i<=n;i++)
        {
            if(dep[i] & 1)cout << "1 ";
            else cout << "2 ";
        }
        cout << '\n';
    }
    return 0;
}