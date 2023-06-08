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
const int N=2e6+5;
const int mod=998244353;
 ll fact[M];
 ll BigMod(ll val,ll pow)
{
    ll res = 1;
    val = val % mod;
    while(pow)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
 void PreCal()
{
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;;
}
 ll nCr(int n,int r)
{
    if(r > n)return 0;
    return (fact[n] * BigMod(fact[r]*fact[n-r], mod-2)) % mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int m,n;cin >> n >> m;
    if(n == 2)
    {
        cout << "0";
        return 0;
    }
    ll ans=0, sum=0;
    for(int i=2;i<=m;i++)sum=(sum + (n-2)*nCr(i-1,n-2)) % mod;
    for(int i=2;i<n;i++)ans = (ans + sum*nCr(n-3,i-2)) % mod;
    cout << ans;
    return 0;
}