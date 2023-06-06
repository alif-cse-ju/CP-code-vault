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

int a[505],par[505];

long long BigMod(long long val,long long pow,long long mod)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

int FindParent(int x)
{
    return (par[x] == x ? x : par[x]=FindParent(par[x]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i], par[i]=i;
    vector<tuple<int,int,int>>edges;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)edges.emplace_back(make_tuple(-((BigMod(a[i],a[j],m) + BigMod(a[j],a[i],m)) % m), i, j));
    }
    sort(edges.begin(),edges.end());
    ll ans=0;
    for(auto [v,x,y] : edges)
    {
        int px=FindParent(x), py=FindParent(y);
        if(px != py)ans += -v, par[py]=px;
    }
    cout << ans;
    return 0;
}
