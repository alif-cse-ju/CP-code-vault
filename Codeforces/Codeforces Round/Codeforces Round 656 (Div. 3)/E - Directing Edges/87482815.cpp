#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
bool visited[200002];
vector<int>order,adj[200002];
void DFS(int x)
    if(visited[x])return;
    visited[x]=true;
    for(int y : adj[x])DFS(y);
    order.emplace_back(x);
int main()
    FAST();
    bool bad;
    int i,m,n,t,x,y,z,pos[200002];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        order.clear();
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            visited[i]=false;
        }
        vector<pair<int,int> >edges;
        while(m--)
        {
            cin >> z >> x >> y;
            if(z)adj[x].emplace_back(y);
            edges.emplace_back(x,y);
        }
        for(i=1;i<=n;i++)
        {
            if(!visited[i])DFS(i);
        }
        reverse(order.begin(),order.end());
        for(i=1;i<=n;i++)pos[order[i-1]]=i;
        bad=false;
        for(i=1;i<=n  &&  !bad;i++)
        {
            for(int it : adj[i])
            {
                if(pos[it] < pos[i])
                {
                    bad=true;
                    break;
                }
            }
        }
        if(bad)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(pair<int,int>it : edges)
            {
                x=it.first,y=it.second;
                if(pos[x] < pos[y])cout << x << ' ' << y << '\n';
                else cout << y << ' ' << x << '\n';
            }
        }
    }
    return 0;
}