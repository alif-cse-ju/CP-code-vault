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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
 ll pw2[M];
int dep[M];
vector<int>adj[M];
 ll BigMod(ll val,ll pow)
{
    ll res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
 void PreCal()
{
    pw2[0]=1;
    for(int i=1;i<M;i++)pw2[i]=(pw2[i-1]*2)%mod;
}
 void DFS(int x,int p)
{
    for(int &y : adj[x])
    {
        if(p ^ y)DFS(y,x), dep[x]=max(dep[x],dep[y]);
    }
    ++dep[x];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)adj[i].clear(), dep[i]=0;
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1,0);
        ll ans=0;
        for(int i=1;i<=n;i++)ans=(ans + dep[i]*pw2[n-1]) % mod;
        cout << ans << '\n';
    }
    return 0;
}