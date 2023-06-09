#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
bool visited[200002];
int w[100002],cnt[100002];
vector<pair<int,int>>adj[100002];
int main()
    FAST();
    int i,m,n,x,y,z;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> w[i];
    for(i=1;i<=m;i++)
    {
        cin >> x >> y;
        ++cnt[x],++cnt[y];
        adj[x].emplace_back(y,i);
        adj[y].emplace_back(x,i);
    }
    queue<int>q;
    vector<int>ans;
    for(i=1;i<=n;i++)
    {
        if(cnt[i] <= w[i])q.emplace(i);
    }
    while(!q.empty())
    {
        x=q.front(),q.pop();
        for(auto it : adj[x])
        {
            y=it.first;
            z=it.second;
            if(visited[z])continue;
            visited[z]=1;
            ans.emplace_back(z);
            if(--cnt[y] == w[y])q.emplace(y);
        }
    }
    if(ans.size() < m)cout << "DEAD";
    else
    {
        cout << "ALIVE\n";
        reverse(ans.begin(),ans.end());
        for(int it : ans)cout << it << ' ';
    }
    return 0;
}