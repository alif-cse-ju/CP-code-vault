#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int mod=1e9+7;

int ans[N],parent[N];
vector<pair<int,int>>adj[N];
pair<pair<int,int>,int>edges[N];

int FindParent(int x)
{
    if(parent[x] == x)return x;
    return parent[x]=FindParent(parent[x]);
}

void DFS(int cur,int par)
{
    int x,y;
    for(auto it : adj[cur])
    {
        x=it.first;
        y=it.second;
        if(!(x ^ par))continue;
        if(ans[cur] == y)
        {
            if(y == 1)ans[x]=2;
            else ans[x]=1;
        }
        else ans[x]=y;
        DFS(x,cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,x,y,z,px,py;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        edges[i].first.first=x;
        edges[i].first.second=y;
        edges[i].second=z;
    }
    for(i=1;i<=n;i++)parent[i]=i;
    for(i=1;i<=m;i++)
    {
        x=edges[i].first.first;
        y=edges[i].first.second;
        z=edges[i].second;
        px=FindParent(x);
        py=FindParent(y);
        if(px != py)
        {
            parent[py]=px;
            adj[x].emplace_back(y,z);
            adj[y].emplace_back(x,z);
        }
    }
    ans[1]=1;
    DFS(1,1);
    for(i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}
