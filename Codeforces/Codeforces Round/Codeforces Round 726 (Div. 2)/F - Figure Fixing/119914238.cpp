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
const int N=2e5+5;
const int mod=1e9+7;
int lvl[N];
ll a[N],b[N];
vector<int>adj[N];
bool visited[N],cycle[N];
ll DFS(int x,int p)
    lvl[x]=lvl[p]+1;
    visited[x]=1;
    for(int y : adj[x])
    {
        if(!visited[y])a[x]+=DFS(y,x);
        else cycle[abs(lvl[x]-lvl[y])]=1;
    }
    return b[x]-a[x];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)
        {
            cin >> b[i];
            adj[i].clear();
            cycle[i]=visited[i]=0;
        }
        while(m--)
        {
            cin >> x >> y;
            if(x == y)cycle[x]=1;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        cycle[0]=0;
        ans=DFS(1,0);
        if(ans == 0ll)cout << "YES\n";
        else
        {
            for(i=0;i<=n;i+=2)
            {
                if(cycle[i])break;
            }
            if(i <= n  &&  ans%2 == 0)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}