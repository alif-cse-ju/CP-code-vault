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
const int mod=1e9+7;
 ll Mul(ll l, ll r)
{
    l %= mod, r %= mod;
    return (l*r) % mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,n;cin >> n >> m;
    ll ans=0, rt=sqrt(n);
    for(int i=1;i<=rt;i++)
    {
        if(i <= m)
        {
            ans += n%i;
            if(ans >= mod)ans -= mod;
        }
        ll r=min(m, n/i), l=max(n/(i+1), rt);
        if(l >= r)continue;
        ll tmp = Mul((Mul(r, r+1) - Mul(l, l+1)), (mod+1)/2);
        ans = (ans + Mul(n, (r-l)) - Mul(i, tmp)) % mod;
    }
    if(m > n)ans = (ans + Mul((m-n), n)) % mod;
    if(ans < 0)ans += mod;
    cout << ans;
    return 0;
}