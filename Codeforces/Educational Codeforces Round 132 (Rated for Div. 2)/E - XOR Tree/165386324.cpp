#pragma GCC optimize("Ofast")
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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
set<int>st[M];
vector<int>adj[M];
int a[M],ans,xr[M];
void DFS1(int x,int p)
    xr[x]=(xr[p]^a[x]);
    for(int y : adj[x])
    {
        if(p ^ y)DFS1(y,x);
    }
int DFS2(int x,int p)
    int bap=x;
    bool ok=1;
    st[bap].insert(xr[x]);
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            int z=DFS2(y,x);
            if(!z)continue;
            if((int)st[bap].size() >= (int)st[z].size())
            {
                for(int v : st[z])ok &= !(st[bap].find((a[x]^v)) != st[bap].end());
                for(int v : st[z])st[bap].insert(v);
                st[z].clear();
            }
            else
            {
                for(int v : st[bap])ok &= !(st[z].find((a[x]^v)) != st[z].end());
                for(int v : st[bap])st[z].insert(v);
                st[bap].clear(), bap=z;
            }
        }
    }
    if(!ok)++ans, st[bap].clear(), bap=0;
    return bap;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS1(1,0);
    int z=DFS2(1,0);
    cout << ans;
    return 0;
}