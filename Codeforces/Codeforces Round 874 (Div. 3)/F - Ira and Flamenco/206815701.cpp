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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll BigMod(ll val,ll pow)
{
    ll res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

ll Cal(vector<int>&a, const int& m)
{
    if((int)a.size() < m)return 0;
    ll mul=1;
    for(int i=0;i<m;i++)mul=(mul*a[i])%mod;
    ll ans=mul;
    for(int i=m;i<(int)a.size();i++)
    {
        mul = (mul * a[i]) % mod;
        mul = (mul * BigMod(a[i-m], mod-2)) % mod;
        ans += mul;
        if(ans >= mod)ans -= mod;
    }
    return ans;
}

ll Solve(vector<pair<int,int>>&b, const int& m)
{
    ll ans=0;
    vector<int>a;
    for(int i=0;i<(int)b.size();)
    {
        a.clear();
        int j=i;
        while(j < (int)b.size())
        {
            auto &[x,y]=b[j];
            if(a.empty()  ||  x == b[j-1].first+1)a.emplace_back(y), ++j;
            else break;
        }
        i=j;
        ans += Cal(a,m);
        if(ans >= mod)ans -= mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        vector<int>a(n);
        for(int &x : a)cin >> x;
        sort(a.begin(),a.end());
        vector<pair<int,int>>b;
        b.emplace_back(a[0],1);
        for(int i=1;i<n;i++)
        {
            auto &[x,y]=b.back();
            if(x == a[i])++y;
            else b.emplace_back(a[i],1);
        }
        cout << Solve(b,m) << '\n';
    }
    return 0;
}
///
