#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
const int mod=1e9+7;
const int sz = (1 << 20);
int m,n;
ll f[sz],g[sz],h[sz],pw[sz],r[sz];
void wht(ll a[])
{
    for(int i=0;i<m;i++)cin >> a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((j >> i) & 1)
            {
                a[j] += a[j ^ (1 << i)];
                if(a[j] >= mod)a[j] -= mod;
            }
        }
    }
}
void iwht(ll a[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((j >> i) & 1)
            {
                a[j] = a[j] - a[j ^ (1 << i)] + mod;
                if(a[j] >= mod)a[j] -= mod;
            }
        }
    }
}
void Do()
{
    pw[0]=1;
    for(int i=1;i<=n;i++)pw[i]=(pw[i-1]*2) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n, m=(1 << n);
    wht(f), wht(g), wht(h);
    for(int i=0;i<m;i++)r[i]=(((f[i] * g[i]) % mod) * h[i]) % mod;
    iwht(r), Do();
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        ans += (r[i] * pw[__builtin_popcount(i)]) % mod;
        if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}