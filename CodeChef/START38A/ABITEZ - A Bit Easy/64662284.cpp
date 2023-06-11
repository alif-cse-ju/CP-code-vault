#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
ll a[M],b[M],c[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int n;cin >> n;
            ll k;cin >> k;
            int m=0;
            for(int i=1;i<=n;i++)
            {
                    ll x;cin >> x;
                    if(x <= k)
                    {
                            ++m;
                            a[m]=x, b[m]=k-x, c[m]=a[m] ^ b[m];
                    }
            }
            if(!m)cout << "0\n";
            else
            {
                    n=m;
                    ll ans=0;
                    map<ll,int>cnt;
                    for(int i=1;i<=n;i++)ans += cnt[a[i]], ++cnt[c[i]];
                    cout << ans << '\n';
            }
    }
    return 0;
}