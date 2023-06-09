#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int child[100002];
LL ttl,mark[100002];
vector<pair<int,LL> >adj[100002];
priority_queue<pair<LL,pair<LL,int> > >pq;
void DFS(int cur,int par)
    int x;LL w,dif;
    for(auto it : adj[cur])
    {
        x=it.first;
        w=it.second;
        if(par ^ x)
        {
            DFS(x,cur);
            ttl+=w*child[x];
            child[cur]+=child[x];
            dif=(w-w/2LL)*child[x];
            pq.push({dif,{w,child[x]}});
        }
    }
    if(!child[cur])++child[cur];
int main()
    FAST();
    LL s,w,dif;
    int i,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(i=1;i<=n;i++)child[i]=0,adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y >> w;
            adj[x].emplace_back(y,w);
            adj[y].emplace_back(x,w);
        }
        ans=ttl=0;
        while(!pq.empty())pq.pop();
        DFS(1,0);
        while(ttl > s)
        {
            ++ans;
            ttl-=pq.top().first;
            w=pq.top().second.first/2LL;
            x=pq.top().second.second;
            pq.pop();
            dif=(w-w/2LL)*x;
            pq.push({dif,{w,x}});
        }
        cout << ans << '\n';
    }
    return 0;
}