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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
bool ok;
ll dist[M];
vector<int>adj[M];
int a[M],par[M],pos[M];
int DFS(int x)
    int mn=INT_MAX;
    for(int y : adj[x])mn=min(mn,DFS(y));
    if(mn < pos[x])ok=0;
    return min(mn,pos[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,r,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<=n;i++)
        {
            cin >> par[i];
            if(par[i] == i)r=i;
            else adj[par[i]].emplace_back(i);
        }
        for(i=1;i<=n;i++)cin >> a[i], pos[a[i]]=i;
        ok=1, x=DFS(r);
        if(!ok  ||  a[1] != r)cout << "-1\n";
        else
        {
            dist[r]=-1;
            for(i=1;i<=n;i++)dist[a[i]]=max(dist[par[a[i]]],dist[a[i-1]])+1;
            for(i=1;i<=n;i++)cout << dist[i]-dist[par[i]] << ' ';
            cout << '\n';
        }
    }
    return 0;
}