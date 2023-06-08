#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
vector<int>adj[N];
long long cnt[2][N];
int n,_time,a[N],start[N],_end[N],lvl[N];
void DFS(int x,int par)
    start[x]=++_time;
    lvl[x]=(lvl[par]+1)%2;
    for(int y : adj[x])
    {
        if(y ^ par)DFS(y,x);
    }
    _end[x]=_time;
void Update(int i,int j,int val)
    while(j <= n)
    {
        cnt[i][j]+=val;
        j+=j & (-j);
    }
long long Query(int i,int j)
    long long ans=0;
    while(j > 0)
    {
        ans+=cnt[i][j];
        j-=j & (-j);
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,x,y,op;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    while(m--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y;
            Update(lvl[x],start[x],y);
            Update(lvl[x],_end[x]+1,-y);
            Update(1-lvl[x],start[x],-y);
            Update(1-lvl[x],_end[x]+1,y);
        }
        else
        {
            cin >> x;
            cout << Query(lvl[x],start[x])+a[x] << '\n';
        }
    }
    return 0;
}