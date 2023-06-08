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
const int N=2e6+5;
const int mod=1e9+7;
 int a[M],dp[M][64],k,n;
 int DP(int i,int mask)
{
    if(i > n)return (__builtin_popcount(mask) == k);
    int ans;
    if(mask < 64  &&  dp[i][mask] != -1)return dp[i][mask];
    ans=DP(i+1,(mask & a[i])) + DP(i+1,mask);
    if(ans >= mod)ans -= mod;
    if(mask < 64)dp[i][mask]=ans;
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            for(int j=0;j<64;j++)dp[i][j]=-1;
        }
        int ans=DP(1,127);
        cout << ans << '\n';
    }
    return 0;
}