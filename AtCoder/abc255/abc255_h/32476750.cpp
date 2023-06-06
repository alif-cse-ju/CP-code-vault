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
const int mod=998244353;

ll Get(ll n)
{
    return ((n*(n+1))/2)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;int q;cin >> n >> q;
    ordered_set<tuple<ll,ll,ll>>ost;
    ost.insert(make_tuple(n,1,0));
    while(q--)
    {
        ll d,l,r;cin >> d >> l >> r;
        int small=ost.order_of_key(make_tuple(l,0,0));
        ll ans=0;
        vector<tuple<ll,ll,ll>>temp;
        for(int i=small;i<(int)ost.size();i++)
        {
            auto [r1,l1,d1]=*(ost.find_by_order(i));
            if(l1 > r)break;
            temp.emplace_back(make_tuple(r1,l1,d1));
            ll v1=(d-d1)%mod, v2=(Get(min(r, r1)%mod) - Get((max(l, l1)-1)%mod) + mod)%mod;
            ans = (ans + v1*v2)%mod;
        }
        cout << ans << '\n';
        auto [r1,l1,d1]=temp[0];
        if(l1 < l)ost.insert(make_tuple(l-1,l1,d1));
        auto [r2,l2,d2]=temp.back();
        if(r2 > r)ost.insert(make_tuple(r2,r+1,d2));
        while(!temp.empty())ost.erase(temp.back()), temp.pop_back();
        ost.insert(make_tuple(r,l,d));
    }
    return 0;
}