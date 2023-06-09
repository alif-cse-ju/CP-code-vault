#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>adj[N];
long long a[N],ans[N],deg[N];
void DFS(int cur)
    for(int it : adj[cur])
    {
        DFS(it);
        a[cur]+=a[it];
        deg[cur]+=deg[it];
        ans[cur]=max(ans[cur],ans[it]);
    }
    if(!deg[cur])++deg[cur];
    ans[cur]=max(ans[cur],(a[cur]+deg[cur]-1LL)/deg[cur]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cin >> x;
        adj[x].emplace_back(i);
    }
    for(i=1;i<=n;i++)cin >> a[i];
    DFS(1);
    cout << ans[1];
    return 0;