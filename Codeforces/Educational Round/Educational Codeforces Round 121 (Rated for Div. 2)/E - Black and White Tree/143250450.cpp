#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
bool inQueue[M];
vector<int>adj[M],adj2[M];
int cnt[M],color[M],par[M];
void DFS(int x,int p)
    cnt[x]=color[x], par[x]=p;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x), cnt[x] += cnt[y];
    }
int main()
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
    for(i=1;i<=n;i++)
    {
        for(int it : adj[i])
        {
            if(i == par[it])
            {
                if(color[i]  ||  cnt[1]-cnt[it] > 1)adj2[i].emplace_back(it);
            }
            else
            {
                if(color[i]  ||  cnt[i] > 1)adj2[i].emplace_back(it);
            }
        }
    }
    queue<int>q;
    for(i=1;i<=n;i++)
    {
        if(color[i])q.emplace(i), inQueue[i]=1;
    }
    while(!q.empty())
    {
        x=q.front(), q.pop();
        for(int it : adj2[x])
        {
            if(!inQueue[it])color[it]=inQueue[it]=1, q.emplace(it);
        }
    }
    for(i=1;i<=n;i++)cout << color[i] << ' ';
    return 0;
}