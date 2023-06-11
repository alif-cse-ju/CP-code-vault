#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[M];
ll BigMod(ll val,ll pow,ll mod)
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,m,n,p,t,x;
    cin >> t;
    while(t--)
    {
        ans=0;
        map<int,int>cnt;
        cin >> n >> m >> p;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=m;i++)cin >> x, ++cnt[x];
        for(i=1;i<=n;i++)
        {
            if(a[i]%p == 0)continue;
            ans += cnt[BigMod(a[i],p-2,p) ^ a[i]];
        }
        cout << ans << '\n';
    }
    return 0;
}