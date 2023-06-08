#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int dist[N],parent[N],sz[N];
bool flag,visited[N];
vector<int>cycle,adj[N];
void DFS1(int x,int par)
    if(flag)return;
    parent[x]=par;
    visited[x]=1;
    for(int y : adj[x])
    {
        if(flag)return;
        if(y ^ par)
        {
            if(!visited[y])DFS1(y,x);
            else
            {
                flag=1;
                int dx,dy;
                dy=x,dx=y;
                while(dy != dx)
                {
                    cycle.emplace_back(dy);
                    dy=parent[dy];
                }
                cycle.emplace_back(dx);
                return;
            }
        }
    }
void DFS2(int x,int par)
{
    sz[x]=1;
    for(int y : adj[x])
    {
        if(y ^ par)
        {
            if(visited[y])continue;
            visited[y]=1;
            dist[y]=dist[x]+1;
            DFS2(y,x);
            sz[x]+=sz[y];
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y;
    long long l,ans,temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cycle.clear();
        for(i=1;i<=n;i++)adj[i].clear(),visited[i]=0,dist[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        flag=0;
        DFS1(1,1);
        l=(int)cycle.size();
        ans=l*(l-1);
        for(i=1;i<=n;i++)visited[i]=sz[i]=0;
        for(int it : cycle)visited[it]=1;
        for(int it : cycle)DFS2(it,it);
        ans=temp=0;
        for(int it : cycle)
        {
            l=sz[it];
            ans+=(l*(l-1))/2;
            ans+=temp*2*sz[it];
            temp+=sz[it];
        }
        cout << ans << '\n';
    }
    return 0;
}