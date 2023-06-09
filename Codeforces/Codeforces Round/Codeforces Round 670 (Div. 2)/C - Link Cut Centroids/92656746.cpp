#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int subTree[N],parent[N];
void DFS(int cur,int par)
    subTree[cur]=1;
    parent[cur]=par;
    for(int x : adj[cur])
    {
        if(x ^ par)
        {
            DFS(x,cur);
            subTree[cur]+=subTree[x];
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y,mn,mx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            subTree[i]=0;
            adj[i].clear();
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1,0);
        mn=INT_MAX;
        for(i=1;i<=n;i++)
        {
            mx=0;
            for(int it : adj[i])
            {
                if(it == parent[i])mx=max(mx,n-subTree[i]);
                else mx=max(mx,subTree[it]);
            }
            if(mx < mn)
            {
                mn=mx;
                x=y=i;
            }
            else if(mn == mx)y=i;
        }
        if(x == y)
        {
            cout << x << ' ' << adj[x][0] << '\n';
            cout << x << ' ' << adj[x][0] << '\n';
        }
        else
        {
            if(adj[y][0] == x)
            {
                cout << y << ' ' << adj[y][1] << '\n';
                cout << x << ' ' << adj[y][1] << '\n';
            }
            else
            {
                cout << y << ' ' << adj[y][0] << '\n';
                cout << x << ' ' << adj[y][0] << '\n';
            }
        }
    }
    return 0;
}