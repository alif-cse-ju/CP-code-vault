#pragma GCC optimize("Ofast")
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
 ll ans;
vector<int>adj[M];
int cnt[M],depth[M],heavyChild[M],inTime[M],L,n,node[M],outTime[M],R,sz[M],timer;
 void DFS(int x,int p)
{
    depth[x]=depth[p]+1, heavyChild[x]=0, inTime[x]=++timer, node[timer]=x, sz[x]=1;
    for(int &y : adj[x])
    {
        if(p ^ y)
        {
            DFS(y,x), sz[x]+=sz[y];
            if(sz[y] > sz[heavyChild[x]])heavyChild[x]=y;
        }
    }
    outTime[x]=timer;
}
 void Update(int i,int v)
{
    while(i <= n)cnt[i]+=v, i+=(i & -i);
}
 int Query(int i)
{
    int ans=0;
    i=max(min(i,n),0);
    while(i)ans+=cnt[i], i-=(i & -i);
    return ans;
}
 void DSU(int x,int p,bool keep)
{
    for(int &y : adj[x])
    {
        if((p^y)  &&  (heavyChild[x]^y))DSU(y,x,0);
    }
    if(heavyChild[x])DSU(heavyChild[x],x,1);
    ans+=Query(n-1-L+depth[x]) - Query(n-2-R+depth[x]);
    Update(depth[x],1);
    for(int &y : adj[x])
    {
        if((p^y)  &&  (heavyChild[x]^y))
        {
            for(int i=inTime[y];i<=outTime[y];i++)ans+=Query(n-1-L-depth[node[i]]+2*depth[x]) - Query(n-2-R-depth[node[i]]+2*depth[x]);
            for(int i=inTime[y];i<=outTime[y];i++)Update(depth[node[i]],1);
        }
    }
    if(!keep)
    {
        for(int i=inTime[x];i<=outTime[x];i++)Update(depth[node[i]],-1);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("awesome.in","r",stdin);
    int t;cin >> t;
    while(t--)
    {
        cin >> n >> L >> R;
        for(int i=1;i<=n;i++)adj[i].clear(), cnt[i]=0;
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y), adj[y].emplace_back(x);
        }
        ans=0, timer=0, DFS(1,0), DSU(1,0,0);
        cout << ans << '\n';
    }
    return 0;
}