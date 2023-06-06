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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

string s[16];
int n,dp[1 << 20][20];

int DP(int mask,int last)
{
    if(__builtin_popcount(mask) == n)return n%2;
    int &ans=dp[mask][last];
    if(ans > -1)return ans;
    if(__builtin_popcount(mask) & 1)
    {
        ans=1;
        for(int i=0;i<n;i++)
        {
            if((mask >> i) & 1)continue;
            if(s[last][(int)s[last].size()-1] == s[i][0])ans &= DP(mask|(1 << i), i);
        }
    }
    else
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            if((mask >> i) & 1)continue;
            if(last == 16  ||  s[last][(int)s[last].size()-1] == s[i][0])ans |= DP(mask|(1 << i), i);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)cin >> s[i];
    memset(dp,-1,sizeof(dp));
    int ans=DP(0,16);
    if(ans)cout << "First";
    else cout << "Second";
    return 0;
}
