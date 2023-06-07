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
const int N=1e6+5;
const int mod=998244353;

ll a[M];

ll Solve()
{
    int n;cin >> n;
    ll x,y;cin >> x >> y;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    if(a[1] > x)return -1;
    ll ans=0;
    for(int i=1;i<=n  &&  x != y;i++)
    {
        if(a[i] <= x)++ans, ++x;
        else
        {
            if(n-i+1 >= i-1)return -1;
            int gain=i+i-n-2; x -= n-i+1, ans += n-i+1;
            ll need=max(0ll, min(a[i]-x-i+1, y-x-i+1)), round=max(0ll, need-1)/gain;
            ans += round*n + min(1ll*i-1, y-x), x += gain*round + min(1ll*i-1,y-x), --i;
        }
    }
    if(x < y)ans+=y-x;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)cout << Solve() << '\n';
    return 0;
}
