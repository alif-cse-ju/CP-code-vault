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
const int mod=998244353;
 const int mx = 2e3+5;
 char s[mx];
int dp[mx][mx];
vector<int>adj[M];
vector<pair<int,char>>path;
 int DP(int i,int j)
{
    if(i >= j)return i == j;
    auto [x1,c1]=path[i];
    auto [x2,c2]=path[j];
    int &ans=dp[x1][x2];
    if(ans > -1)return ans;
    if(c1 == c2)ans=DP(i+1,j-1) + 2;
    else ans=max(DP(i+1,j), DP(i,j-1));
    return dp[x2][x1]=ans;
}
 int DFS(int x,int p)
{
    path.emplace_back(x,s[x]);
    int ans=DP(0,(int)path.size()-1);
    for(int &y : adj[x])
    {
        if(p ^ y)ans=max(ans, DFS(y,x));
    }
    path.pop_back();
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n >> s+1;
        for(int i=0;i<=n;i++)
        {
            adj[i].clear();
            for(int j=0;j<=n;j++)dp[i][j]=-1;
        }
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans, DFS(i,0));
        cout << ans << '\n';
    }
    return 0;
}