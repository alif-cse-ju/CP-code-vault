#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
double b,mx,a[200005];
vector<int>ans,temp,adj[200005];
bool valid[200005],visited[200005];
void DFS(int x)
{
    if(!valid[x]  ||  visited[x])return;
    visited[x]=1;
    temp.emplace_back(x);
    for(int y : adj[x])DFS(y);
}
int main()
{
    FAST();
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        mx=0;
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            adj[i].clear();
            valid[i]=visited[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            cin >> b;
            a[i]/=b,mx=max(mx,a[i]);
        }
        while(m--)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        for(i=1;i<=n;i++)
        {
            if(a[i] == mx)valid[i]=1;
        }
        ans.clear();
        for(i=1;i<=n;i++)
        {
            if(valid[i])
            {
                if(!visited[i])
                {
                    temp.clear();
                    DFS(i);
                    if(temp.size() > ans.size())ans=temp;
                }
            }
        }
        cout << ans.size() << '\n';
        for(int x : ans)cout << x << ' ';
        cout << '\n';
    }
    return 0;
}