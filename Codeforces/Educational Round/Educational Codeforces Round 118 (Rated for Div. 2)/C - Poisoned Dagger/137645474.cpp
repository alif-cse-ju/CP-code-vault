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
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int n;
ll a[102],h;
bool Check(ll v)
    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        ans += min(v,a[i]-a[i-1]);
        if(ans >= h)return 1;
    }
    return (h-ans <= v);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t;
    ll l,m,r;
    cin >> t;
    while(t--)
    {
        cin >> n >> h;
        for(i=1;i<=n;i++)cin >> a[i];
        l=1,r=1e18;
        while(l <= r)
        {
            m=(l+r) >> 1ll;
            if(Check(m))r=m-1;
            else l=m+1;
        }
        cout << r+1 << '\n';
    }
    return 0;
}