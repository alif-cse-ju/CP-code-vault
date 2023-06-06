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
const int N=2e6+5;
const int mod=1e9+7;

const int mx = 2e3+5;

int dp[mx][mx],ncr[mx][mx];

void PreCal()
{
    dp[0][0]=ncr[0][0]=1;
    for(int i=1;i<mx;i++)
    {
        dp[i][i]=ncr[i][0]=ncr[i][i]=1;
        for(int j=1;j<i;j++)
        {
            dp[i][j]=dp[i-1][j] + dp[i-1][j-1];
            if(dp[i][j] >= mod)dp[i][j] -= mod;
            ncr[i][j]=ncr[i-1][j] + ncr[i-1][j-1];
            if(ncr[i][j] >= mod)ncr[i][j] -= mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;cin >> n >> k;
    PreCal();
    for(int i=1;i<=k;i++)cout << (1ll * ncr[n-k+1][i] * dp[k][i]) % mod << '\n';
    return 0;
}
