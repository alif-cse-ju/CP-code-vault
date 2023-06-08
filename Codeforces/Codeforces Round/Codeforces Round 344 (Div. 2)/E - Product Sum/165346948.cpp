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
const long long inv=-(1LL << 62);
bool Min;
struct Line
    long long m,b;
    mutable function<const Line*()>succ;
    bool operator<(const Line &rhs)const
    {
        if(rhs.b!=inv)return m < rhs.m;
        const Line *s=succ();
        if(!s)return 0;
        long long x=rhs.m;
        return b-s->b < (s->m-m)*x;
    }
};
 struct HullDynamic:public multiset<Line>
{
    bool bad(iterator y)
    {
        auto z=next(y);
        if(y==begin())
        {
            if(z==end())return 0;
            return y->m==z->m&&y->b<=z->b;
        }
        auto x=prev(y);
        if(z==end())return y->m==x->m&&y->b<=x->b;
        return 1.0*(x->b-y->b)*(z->m-y->m)>=1.0*(y->b-z->b)*(y->m-x->m);
    }
     void Insert(long long m, long long b)
    {
        if(Min)m*=-1, b*=-1;
        auto y=insert({m,b});
        y->succ=[=] {return next(y)==end()?0:&*next(y);};
        if(bad(y))
        {
            erase(y);
            return;
        }
        while(next(y)!=end()&&bad(next(y)))erase(next(y));
        while(y!=begin()&&bad(prev(y)))erase(prev(y));
    }
     long long Query(long long x)
    {
        auto l=*lower_bound((Line){ x,inv });
        long long ret=l.m*x+l.b;
        if(Min)ret *= -1;
        return ret;
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
    HullDynamic hd;
    for(int i=2; i<=n; i++)
    {
        hd.Insert(i-1, -sum[i-2]);
        ans=max(ans, dp[n]+sum[i-1]-a[i]*i+hd.Query(a[i]));
    }
    hd.clear();
    for(int i=n-1; i; i--)
    {
        hd.Insert(i+1, -sum[i+1]);
        ans=max(ans, dp[n]+sum[i]-a[i]*i+hd.Query(a[i]));
    }
    cout << ans;
    return 0;
}