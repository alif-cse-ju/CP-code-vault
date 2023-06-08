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
const int N=2e6+5;
const int mod=1e9+7;
 int _time[M];
vector<pair<int,int>>adj[M];
 void DFS(int x,int p,int t)
{
    for(auto &[y,z] : adj[x])
    {
        if(p ^ y)
        {
            _time[y]=_time[x];
            if(z < t)++_time[y];
            DFS(y,x,z);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    _time[1]=1;
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y,i);
            adj[y].emplace_back(x,i);
        }
        DFS(1,0,0);
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans, _time[i]);
        cout << ans << '\n';
    }
    return 0;
}
///