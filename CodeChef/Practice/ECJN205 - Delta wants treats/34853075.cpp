#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    bool mark[10002];
    vector<int>adj[10002];
    int i,m,n,t,x,y,z,dist[10002];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            mark[i]=0;
            adj[i].clear();
            dist[i]=INT_MAX;
        }
        for(i=0;i<m;i++)
        {
            cin >> x;
            mark[x]=true;
        }
        cin >> m;
        while(m--)
        {
            cin >> x >> y;
            if(!mark[x]  ||  !mark[y])continue;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        cin >> x >> y;
        queue<pair<int,int> >q;
        q.emplace(x,0),dist[x]=0;
        while(!q.empty())
        {
            x=q.front().first;
            z=q.front().second+1;q.pop();
            for(int it : adj[x])
            {
                if(dist[it] > z)
                {
                    dist[it]=z;
                    q.emplace(it,z);
                }
            }
        }
        if(dist[y] == INT_MAX)cout << "-1\n";
        else cout << dist[y] << '\n';
    }
    return 0;
}