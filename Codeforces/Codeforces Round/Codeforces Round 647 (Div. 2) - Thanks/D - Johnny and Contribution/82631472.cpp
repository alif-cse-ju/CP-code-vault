#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int pos[500005];
vector<int>adj[500005];
pair<int,int>order[500005];
int main()
    FAST();
    int i,m,n,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)
    {
        cin >> pos[i];
        order[i]={pos[i],i};
    }
    vector<int>ans;
    set<int>neighbours;
    sort(order+1,order+n+1);
    for(i=1;i<=n;i++)
    {
        for(int x : adj[i])
        {
            if(pos[i] == pos[x])
            {
                cout << "-1";
                return 0;
            }
        }
        x=order[i].second;
        ans.emplace_back(x);
        neighbours.clear();
        for(int y : adj[x])
        {
            if(pos[y] < pos[x])neighbours.insert(pos[y]);
        }
        if(neighbours.size() < pos[x]-1)
        {
            cout << "-1";
            return 0;
        }
    }
    for(int x : ans)cout << x << ' ';
    return 0;
}