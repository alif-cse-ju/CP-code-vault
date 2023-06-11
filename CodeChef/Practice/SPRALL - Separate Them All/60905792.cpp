#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll ans;
int deg[M];
vector<int>adj[M];
void DFS(int x,int p)
{
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    if(p)ans += deg[p], --deg[p];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tmp;
    int i,n,t,q,x,xx,y,yy;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        for(i=1;i<=n;i++)deg[i]=(int)adj[i].size();
        ans=0, DFS(1,0);
        for(i=1;i<=n;i++)deg[i]=(int)adj[i].size();
        cout << ans << '\n';
        while(q--)
        {
            cin >> x >> y >> xx >> yy;
            if((x == xx  &&  y == yy)  ||  (x == yy  &&  y == xx))tmp=0;
            else if(x == xx)tmp=deg[yy]-deg[y]+1;
            else if(x == yy)tmp=deg[xx]-deg[y]+1;
            else if(y == xx)tmp=deg[yy]-deg[x]+1;
            else if(y == yy)tmp=deg[xx]-deg[x]+1;
            else tmp=deg[xx]+deg[yy]-deg[x]-deg[y]+2;
            cout << ans+tmp << '\n';
        }
    }
    return 0;
}