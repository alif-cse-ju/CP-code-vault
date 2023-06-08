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
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
const int M=3e5+5;
int a[M],ok[M];
vector<int>adj[M];
void DFS(int x)
{
    if(ok[x] > -1)return;
    ok[x]=0;
    for(int y : adj[x])
    {
        DFS(y), ok[x]|=ok[y];
        if(ok[x])return;
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        ok[n+1]=1;
        for(int i=1;i<=n;i++)cin >> a[i], ok[i]=-1, adj[i].clear();
        for(int i=1;i<=n;i++)
        {
            if(i-a[i] > 0)adj[i-a[i]].emplace_back(i+1);
            if(i+a[i] <= n)adj[i].emplace_back(i+a[i]+1);
        }
        DFS(1);
        if(ok[1])cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}