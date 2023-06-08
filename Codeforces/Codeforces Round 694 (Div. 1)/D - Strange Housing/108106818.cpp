#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
deque<int>dq;
bool visited[N];
vector<int>ans,adj[N];
void DFS(int x)
    visited[x]=1;
    for(int y : adj[x])
    {
        if(!visited[y])DFS(y);
    }
void Solve()
    int x;
    while(!dq.empty())
    {
        x=dq.front();
        dq.pop_front();
        for(int it1 : adj[x])
        {
            if(!visited[it1])
            {
                visited[it1]=1;
                ans.emplace_back(it1);
                for(int it2 : adj[it1])
                {
                    if(!visited[it2])
                    {
                        visited[it2]=1;
                        dq.emplace_back(it2);
                    }
                }
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
            adj[i].clear();
        }
        while(m--)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1);
        for(i=1;i<=n;i++)
        {
            if(!visited[i])break;
        }
        if(i <= n)cout << "NO\n";
        else
        {
            cout << "YES\n";
            ans.clear();
            for(i=1;i<=n;i++)visited[i]=0;
            visited[1]=1;
            ans.emplace_back(1);
            for(int it : adj[1])
            {
                visited[it]=1;
                dq.emplace_back(it);
            }
            Solve();
            cout << (int)ans.size() << '\n';
            for(int it : ans)cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;
}
//