#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=4e5+5;
const int mod=1e9+7;
int ans[N];
set<int>loop;
bool lp[N],visited[N];
vector<int>adj[N],par[N];
void DFS1(int x)
    if(visited[x])
    {
        if(lp[x])loop.insert(x);
        return;
    }
    lp[x]=visited[x]=1;
    for(int y : adj[x])DFS1(y);
    lp[x]=0;
 void DFS2(int x)
{
    if(visited[x])return;
    visited[x]=1;
    for(int y : adj[x])DFS2(y);
}
 void DFS3(int x)
{
    for(int y : adj[x])
    {
        if(ans[y] < 0)continue;
        ++ans[y];
        if(ans[y] > 1)loop.insert(y);
        else DFS3(y);
    }
}
 void DFS4(int x)
{
    if(ans[x] == -1  ||  visited[x])return;
    ans[x]=2,visited[x]=1;
    for(int y : adj[x])DFS4(y);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            par[i].clear();
            lp[i]=visited[i]=0;
        }
        loop.clear();
        while(m--)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            par[y].emplace_back(x);
        }
        DFS1(1);
        for(i=1;i<=n;i++)
        {
            if(visited[i])ans[i]=1;
            else ans[i]=0;
            visited[i]=0;
        }
        for(int it : loop)DFS2(it);
        for(i=1;i<=n;i++)
        {
            if(visited[i])ans[i]=-1;
        }
        if(ans[1] > 0)
        {
            for(i=2;i<=n;i++)
            {
                if(ans[i] == 1)ans[i]=0;
            }
            loop.clear();
            DFS3(1);
            for(i=1;i<=n;i++)visited[i]=0;
            for(int it : loop)DFS4(it);
        }
        for(i=1;i<=n;i++)cout << min(2,ans[i]) << ' ';
        cout << '\n';
    }
    return 0;
}