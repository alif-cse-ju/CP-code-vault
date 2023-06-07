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
    mutable ll m, b, p;
    bool operator<(const Line& l) const { return m < l.m; }
    bool operator<(ll x) const { return p < x; }
struct LineContainer : multiset<Line, less<>>
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
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,d,n,caseNo=0;
    while(scanf("%d %d %d",&n,&c,&d) == 3)
    {
        if(!n  &&  !c  &&  !d)break;
        vector<tuple<int,int,int,int>>nodes;
        for(int i=0;i<n;i++)
        {
            int w,x,y,z;scanf("%d %d %d %d",&w,&x,&y,&z);
            nodes.emplace_back(make_tuple(w,x,y,z));
        }
        sort(nodes.begin(),nodes.end());
        LineContainer lc;
        lc.Insert(0, c);
        for(auto [w,x,y,z] : nodes)
        {
            ll v=lc.Query(w);
            if(v < x)continue;
            v += y-x-1ll*z*w-z, lc.Insert(z, v);
        }
        printf("Case %d: %lld\n",++caseNo,lc.Query(d+1));
    }
    return 0;
}