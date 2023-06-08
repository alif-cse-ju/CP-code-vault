#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
bool visited[M];
int lx,ly,par[M];
vector<int>temp[M];
set<int>adj[M],child[M];
vector<pair<int,int>>conComp;
vector<pair<pair<int,int>,pair<int,int>>>ans;
void DFS1(int x)
    for(int y : adj[x])
    {
        if(par[x] ^ y)
        {
            par[y]=x;
            child[x].insert(y);
            DFS1(y);
        }
    }
    if((int)child[x].size() > 1)
    {
        int y;
        while((int)child[x].size() > 2)
        {
            y=*(child[x].begin());
            adj[x].erase(y);
            adj[y].erase(x);
            child[x].erase(y);
            ans.push_back({{x,y},{0,0}});
        }
        if(par[x])
        {
            adj[x].erase(par[x]);
            child[par[x]].erase(x);
            temp[par[x]].emplace_back(x);
            ans.push_back({{x,par[x]},{0,0}});
        }
    }
    for(int it : temp[x])adj[x].erase(it);
}
 void DFS2(int x,int p)
{
    visited[x]=1;
    if((int)adj[x].size() <= 1)
    {
        if(lx)ly=x;
        else lx=ly=x;
    }
    for(int y : adj[x])
    {
        if(y ^ p)DFS2(y,x);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            temp[i].clear();
            child[i].clear();
        }
        ans.clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        DFS1(1);
        conComp.clear();
        for(i=1;i<=n;i++)visited[i]=0;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                lx=ly=0;
                DFS2(i,0);
                conComp.emplace_back(lx,ly);
            }
        }
        l=(int)ans.size();
        for(i=0;i<l;i++)
        {
            ans[i].second.first=conComp[i].second;
            ans[i].second.second=conComp[i+1].first;
        }
        cout << l << '\n';
        for(auto it : ans)cout << it.first.first << ' ' << it.first.second << ' ' << it.second.first << ' ' << it.second.second << '\n';
    }
    return 0;
}