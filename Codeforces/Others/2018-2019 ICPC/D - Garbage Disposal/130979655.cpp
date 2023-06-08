#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &x:a) cin >> x;
    ll ans = a[0]/k;
    ll t = a[0] - ans*k;
    for (int i = 1; i < n ; ++i)
    {
        ll T = t + a[i];
        ll p = T/k;
        if(!p && t != 0)
        {
            ans++;
            t = 0;
            continue;
        }
        ans+=p;
        t = T - p*k;
    }
    if(t!=0) ans++;
    cout << ans << "\n";
    return 0;
}