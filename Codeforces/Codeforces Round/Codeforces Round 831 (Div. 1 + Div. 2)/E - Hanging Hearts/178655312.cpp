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
const int mod=1e9+7;
 int ans[M];
vector<int>adj[M];
 void DFS1(int x)
{
    for(int &y : adj[x])DFS1(y), ans[x]=max(ans[x], ans[y]);
    ++ans[x];
}
 ll DFS2(int x)
{
    ll dp=0;
    for(int &y : adj[x])dp += DFS2(y);
    return max(dp, 1ll*ans[x]);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=2;i<=n;i++)
    {
        int p;cin >> p;
        adj[p].emplace_back(i);
    }
    DFS1(1);
    cout << DFS2(1);
    return 0;
}