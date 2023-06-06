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

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

ll dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,k,n;cin >> n >> k >> c;
    ll tmp=(1ll*c*(c-1))%mod; //To ensure that at least 2 colors are used
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1];
        dp[i]+=dp[i-1];
        if(dp[i] >= mod)dp[i]-=mod;
        dp[i]+=tmp;
        if(dp[i] >= mod)dp[i]-=mod;
        if(i-k > 0)dp[i]=(dp[i]+1ll*(c-2)*dp[i-k+1])%mod;
    }
    cout << (dp[n]+c)%mod;
    return 0;
}