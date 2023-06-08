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
 const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 bool Solve()
{
    int n;cin >> n;
    vector<int>a(n);
    for(int &x : a)cin >> x;
    sort(a.begin(),a.end());
    if(a[0] > 1)return 0;
    ll sum=1;
    for(int i=1;i<n;i++)
    {
        if(a[i] > sum)return 0;
        sum += a[i];
    }
    return 1;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)cout << (Solve() ? "YES" : "NO") << '\n';
    return 0;
}