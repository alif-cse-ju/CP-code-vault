#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

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
const int N=2e6+5;
const int mod=1e9+7;

#pragma once

struct Line
{
    mutable ll m, b, p;
    bool operator<(const Line& l) const { return m < l.m; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>>
{
    const long long inf=LLONG_MAX;

    long long div(long long a, long long b) { return a/b - ((a ^ b) < 0 && a % b); }

    bool isect(iterator x, iterator y)
    {
        if (y == end()) { x->p = inf; return false; }
        if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
        else x->p = div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }

    void Insert(long long m, long long b)
    {
        auto z = insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }

    long long Query(long long v)
    {
        assert(!empty());
        auto l=*lower_bound(v);
        return (l.m*v + l.b);
    }
};

ll a[M],dp[M],sum[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=1; i<=n; i++)cin >> a[i], dp[i]=dp[i-1]+a[i]*i, sum[i]=sum[i-1]+a[i];
    ll ans=dp[n];
    LineContainer lc;
    for(int i=2; i<=n; i++)
    {
        lc.Insert(i-1, -sum[i-2]);
        ans=max(ans, dp[n]+sum[i-1]-a[i]*i+lc.Query(a[i]));
    }
    lc.clear();
    for(int i=n-1; i; i--)
    {
        lc.Insert(i+1, -sum[i+1]);
        ans=max(ans, dp[n]+sum[i]-a[i]*i+lc.Query(a[i]));
    }
    cout << ans;
    return 0;
}