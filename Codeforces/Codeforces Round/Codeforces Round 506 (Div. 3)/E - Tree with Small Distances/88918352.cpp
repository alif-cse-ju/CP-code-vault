#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<int>adj[200002];
int lvl[200002],par[200002];
void DFS(int cur,int parent)
    lvl[cur]=lvl[parent]+1;
    par[cur]=parent;
    for(int x : adj[cur])
    {
        if(x ^ parent)DFS(x,cur);
    }
int main()
    FAST();
    int i,n,x,y,ans=0;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    set<pair<int,int>>st;
    for(i=2;i<=n;i++)
    {
        if(lvl[i] > 3)st.insert({lvl[i],i});
    }
    while(!st.empty())
    {
        ++ans;
        auto it=*(--st.end());
        x=par[it.second],st.erase({lvl[x],x});
        for(y : adj[x])
        {
            if(st.find({lvl[y],y}) != st.end())st.erase({lvl[y],y});
        }
    }
    cout << ans;
    return 0;
}