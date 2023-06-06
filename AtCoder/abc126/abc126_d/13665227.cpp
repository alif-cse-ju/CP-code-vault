#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int ans[100002];
vector<pair<int,int> >adj[100002];

void DFS(int x,int y,int cost)
{
    if(ans[y] != -1)return;
    if(x == 0)ans[y]=0;
    else ans[y]=(ans[x]+cost)%2;
    for(pair<int,int> z : adj[y])DFS(y,z.first,z.second);
}

int main()
{
    FAST();
    int i,n,x,y,z;
    cin >> n;
    ans[1]=-1;
    for(i=2;i<=n;i++)
    {
        ans[i]=-1;
        cin >> x >> y >> z;
        z%=2;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    DFS(0,1,1);
    for(i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}
