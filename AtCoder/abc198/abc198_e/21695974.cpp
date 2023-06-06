#include<bits/stdc++.h>

using namespace std;

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

set<int>ans;
bool mark[M];
int color[M];
vector<int>adj[M];

void DFS(int x,int par)
{
    bool flag=0;
    if(!mark[color[x]])
    {
        flag=1;
        ans.insert(x);
        mark[color[x]]=1;
    }
    for(int y : adj[x])
    {
        if(y ^ par)DFS(y,x);
    }
    if(flag)mark[color[x]]=0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)cin >> color[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    for(int it : ans)cout << it << '\n';
    return 0;
}