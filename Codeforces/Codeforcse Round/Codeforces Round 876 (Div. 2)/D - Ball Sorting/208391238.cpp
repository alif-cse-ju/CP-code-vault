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
 const int mx = 502;
 int a[mx],dp[mx][mx],n;
 int DP(int i,int k)
{
    if(k < 0)return -N;
    if(i == n)return 0;
    int &ans=dp[i][k];
    if(ans != -1)return ans;
    if(k)ans=0;
    else ans=-N;
    for(int j=i+1;j<=n;j++)
    {
        if(a[i] < a[j])ans=max(ans, DP(j,k-(j > i+1))+1);
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int j=0;j<=n;j++)dp[0][j]=-1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            for(int j=0;j<=n;j++)dp[i][j]=-1;
        }
        for(int i=1;i<=n;i++)cout << n-DP(0,i) << ' ';
        cout << '\n';
    }
    return 0;
}
///