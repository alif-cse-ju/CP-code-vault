#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int indeg[200002];
vector<int>adj[200002];
int main()
{
    FAST();
    int i,m,n,x,y,ans;
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> x >> y;
        ++indeg[x],++indeg[y];
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    if(m < n)
    {
        cout << "0";
        return 0;
    }
    ans=m;
    queue<int>q;
    for(i=1;i<=n;i++)
    {
        if(indeg[i] == 1)q.emplace(i);
    }
    while(!q.empty())
    {
        --ans;
        x=q.front(),q.pop();
        for(int it : adj[x])
        {
            if(--indeg[it] == 1)q.emplace(it);
        }
    }
    cout << ans;
    return 0;
}