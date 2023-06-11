#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll a[N],sz[N];
vector<int>adj[N];
ll DFS(int x,int p)
{
    sz[x]=0;
    ll tmp=0;
    for(int y : adj[x])
    {
        if(p ^ y)tmp += DFS(y,x), sz[x] += sz[y];
    }
    if(x > 1  &&  (int)adj[x].size() == 1)
    {
        ++sz[x];
        if(!a[x])return 1000000000000ll;
        return a[x];
    }
    if(!a[x])return tmp;
    return min(tmp, a[x]*sz[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        for(i=1;i<=n;i++)cin >> a[i];
        if(n == 1)cout << a[1] << '\n';
        else cout << DFS(1,0) << '\n';
    }
    return 0;
}