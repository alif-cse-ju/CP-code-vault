#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int child[200002];
LL ans,val[200002];
bool visited[200002];
vector<int>order,par[200002];
void DFS(int cur)
    if(child[cur] == -1  ||  visited[cur])return;
    visited[cur]=1;
    par[child[cur]].emplace_back(cur);
    DFS(child[cur]);
void Take(int cur)
    if(par[cur].empty())
    {
        if(val[cur] >= 0)
        {
            ans+=val[cur];
            visited[cur]=1;
            order.emplace_back(cur);
        }
        return;
    }
    for(int x : par[cur])
    {
        Take(x);
        val[cur]+=max(0LL,val[x]);
    }
    if(val[cur] >= 0)
    {
        ans+=val[cur];
        visited[cur]=1;
        order.emplace_back(cur);
    }
}
 void NowTake(int cur)
{
    if(!visited[cur])
    {
        ans+=val[cur];
        order.emplace_back(cur);
    }
    for(int x : par[cur])NowTake(x);
}
 int main()
{
    FAST();
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> val[i];
    for(i=1;i<=n;i++)cin >> child[i];
    for(i=1;i<=n;i++)
    {
        if(!visited[i])DFS(i);
    }
    for(i=1;i<=n;i++)visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if(child[i] == -1)Take(i);
    }
    for(i=1;i<=n;i++)
    {
        if(child[i] == -1)NowTake(i);
    }
    cout << ans << '\n';
    for(int x : order)cout << x << ' ';
    return 0;
}