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

int ans[M];
vector<int>st[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        ll x;cin >> x;
        int completed=1;
        if(x < 0)
        {
            ll dif=-1-x;
            completed += dif/i, x += 1ll*(completed-1)*i;
        }
        for(int j=completed;j<=m;j++)
        {
            x += i;
            if(x < n)st[x].emplace_back(j);
            else break;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j : st[i])ans[j] += (i == ans[j]);
    }
    for(int i=1;i<=m;i++)cout << ans[i] << '\n';
    return 0;
}