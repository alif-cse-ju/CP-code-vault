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
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin >> T;
    while(T--)
    {
        int m,n,r;cin >> n >> m >> r;
        bool free[n+1][m+1][r+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=r;k++)free[i][j][k]=1;
            }
        }
        for(int i=1;i<=r;i++)
        {
            int coord,d,t;cin >> t >> d >> coord;
            if(d == 1)
            {
                for(int j=0;j<=m;j++)
                {
                    int cur=t-coord-j;
                    if(cur >= 0  &&  cur <= r)free[coord][j][cur]=0;
                }
            }
            else
            {
                for(int j=0;j<=n;j++)
                {
                    int cur=t-coord-j;
                    if(cur >= 0  &&  cur <= r)free[j][coord][cur]=0;
                }
            }
        }
        bool dp[n+1][m+1][r+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    dp[i][j][k]=!(i || j || k);
                    if(!free[i][j][k])continue;
                    if(i)dp[i][j][k] |= dp[i-1][j][k];
                    if(j)dp[i][j][k] |= dp[i][j-1][k];
                    if(k)dp[i][j][k] |= dp[i][j][k-1];
                }
            }
        }
        int ans=-1;
        for(int k=0;k<=r;k++)
        {
            if(dp[n][m][k])
            {
                ans=k+m+n;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
///