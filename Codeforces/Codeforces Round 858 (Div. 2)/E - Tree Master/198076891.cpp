/// Lower bound on BIT in O(logn)
/// https://codeforces.com/contest/992/problem/E

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

const int magic = 320;
vector<vector<ll>>dp[M];
int a[M],cnt[M],lvl[M],koto[M],par[M];

ll DP(int x,int y)
{
    if(x == 1)return 1ll*a[1]*a[1];
    if(cnt[lvl[x]] > magic)return 1ll*a[x]*a[y]+DP(par[x],par[y]);
    if(!dp[lvl[x]][koto[x]][koto[y]])dp[lvl[x]][koto[x]][koto[y]]=dp[lvl[x]][koto[y]][koto[x]]=1ll*a[x]*a[y]+DP(par[x],par[y]);
    return dp[lvl[x]][koto[x]][koto[y]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=2;i<=n;i++)
    {
        cin >> par[i];
        lvl[i]=lvl[par[i]]+1, ++cnt[lvl[i]], koto[i]=cnt[lvl[i]];
    }
    for(int i=1;i<n;i++)
    {
        if(cnt[i] <= magic)dp[i]=vector<vector<ll>>(cnt[i]+1, vector<ll>(cnt[i]+1, 0));
    }
    while(q--)
    {
        int x,y;cin >> x >> y;
        cout << DP(x,y) << '\n';
    }
    return 0;
}