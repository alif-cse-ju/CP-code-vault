#pragma GCC optimize("Ofast")
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
const int N=2e6+5;
const int mod=1e9+7;
bool mark[M];
vector<int>adj[M];
multiset<int>mst[M];
int ans,cnt[M],d,dist[M],m;
void DFS1(int x,int p)
    cnt[x]=mark[x], dist[x]=-1;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS1(y,x);
            cnt[x] += cnt[y], dist[x]=max(dist[x], dist[y]), mst[x].insert(dist[y]+1);
        }
    }
    if(cnt[x])++dist[x];
}
 void DFS2(int x,int p,int mx)
{
    if(max(dist[x], mx)  <=  d)++ans;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            mst[x].erase(mst[x].find(dist[y]+1));
            int v;
            if(mst[x].empty()  ||  *(--mst[x].end()) < 1)v=0;
            else v=*(--mst[x].end())+1;
            DFS2(y,x,max(mx+(cnt[y] < m), v));
            mst[x].insert(dist[y]+1);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n >> m >> d;
    for(int i=0;i<m;i++)
    {
        int x;cin >> x;
        mark[x]=1;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS1(1,0);
    DFS2(1,0,0);
    cout << ans << '\n';
    return 0;
}