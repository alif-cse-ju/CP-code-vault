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

#define ll long long

ll dp[1 << 20][20];
int a[20],bonus[20][20],m,n;

ll DP(int mask, int last)
{
    if(__builtin_popcount(mask) == m)return 0;
    ll &ans=dp[mask][last];
    if(ans > -1)return ans;
    ans=0;
    for(int i=0;i<n;i++)
    {
        if((mask >> i) & 1)continue;
        ans=max(ans, a[i] + bonus[last][i] + DP(mask | (1 << i), i));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;cin >> n >> m >> k;
    for(int i=0;i<n;i++)cin >> a[i];
    while(k--)
    {
        int x,y,z;cin >> x >> y >> z;
        bonus[x-1][y-1]=z;
    }
    memset(dp,-1,sizeof(dp));
    cout << DP(0, 18);
    return 0;
}
