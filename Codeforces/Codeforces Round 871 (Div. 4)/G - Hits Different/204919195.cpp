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
const int N=1e6+5;
const int mod=998244353;
 ll dp[N];
 int Get(int n)
{
    return (n*(n+1))/2;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1]=1, dp[2]=5, dp[3]=10;
    for(int i=3;i<2022;i++)
    {
        int it1=Get(i-3)+1, it2=Get(i-2)+1, L=Get(i-1)+1, R=Get(i);
        if(L >= N)break;
        dp[L]=dp[it2]+1ll*L*L, dp[R]=dp[L-1]+1ll*R*R;
        for(int j=L+1;j<min(N-4,R);j++)dp[j]=dp[it2]+dp[++it2]+1ll*j*j - dp[it1++];
    }
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}