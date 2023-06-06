#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

const int M=4e5+5;
const int N=2e6+5;
const int mod=998244353;

ll invPow;

ll Do(ll x, ll y)
{
    x %= mod, y %= mod;
    return (x * y) % mod;
}

void PreCal()
{
    invPow=1;
    ll pw=mod-2, v=2;
    while(pw > 0)
    {
        if(pw & 1)invPow=Do(invPow, v);
        pw=pw >> 1;
        v=Do(v, v);
    }
}

ll Give(ll n)
{
    return Do(Do(n, n+1), invPow);
}

ll Calculate(ll l, ll r)
{
    l %= mod, r %= mod;
    ll tmp=(Give(r) - Give(l)) % mod;
    if(tmp < 0)tmp += mod;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    ll n; int q;cin >> n >> q;
    ordered_set<tuple<ll,ll,ll>>ost;
    ost.insert(make_tuple(1,n,0));

    while(q--)
    {
        ll d,l,r;cin >> d >> l >> r;
        int id=ost.order_of_key(make_tuple(l,0,0));
        auto [la,ra,da]=*(ost.find_by_order(id));
        if(la != l)--id;
        vector<tuple<ll,ll,ll>>v;
        for(int i=id;i<(int)ost.size();i++)
        {
            auto [lb,rb,db]=*(ost.find_by_order(i));
            if(lb > r)break;
            v.emplace_back(make_tuple(lb,rb,db));
        }
        ll tmp=0;
        for(auto [lb,rb,db] : v)tmp=(tmp - Do(Calculate(lb-1,rb), db)) % mod, ost.erase(ost.find_by_order(ost.order_of_key(make_tuple(lb,rb,db))));
        if(get<0>(v[0]) < l)
        {
            auto [lb,rb,db]=v[0];
            tmp = (tmp + Do(Calculate(lb-1,l-1), db)) % mod;
            ost.insert(make_tuple(lb,l-1,db));
        }
        ost.insert(make_tuple(l,r,d));
        if(get<1>(v.back()) > r)
        {
            auto [lb,rb,db]=v.back();
            tmp = (tmp + Do(Calculate(r,rb), db)) % mod;
            ost.insert(make_tuple(r+1,rb,db));
        }


        tmp = (Do(Calculate(l-1,r), d) + tmp ) % mod;
        if(tmp < 0)tmp += mod;
        cout << tmp << '\n';
    }
    return 0;
}
