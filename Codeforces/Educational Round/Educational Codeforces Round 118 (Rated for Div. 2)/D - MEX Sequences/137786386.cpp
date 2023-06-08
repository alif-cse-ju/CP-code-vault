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
const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;
ll dp[M];
int a[M],cnt[M];
ll BigMod(ll val,ll pow)
    ll res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,temp;
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<=n+2;i++)cnt[i]=dp[i]=0;
        for(i=1;i<=n;i++)cin >> a[i], ++cnt[a[i]];
        ans=BigMod(2,cnt[0]+cnt[2])+BigMod(2,cnt[1])-2;
        for(i=1;i<=n;i++)
        {
            --cnt[a[i]];
            if(!a[i])dp[0]=(dp[0]*2ll+1)%mod;
            else dp[a[i]]=(dp[a[i]-1]+dp[a[i]]+dp[a[i]])%mod;
            if(!a[i])continue;
            if(a[i] == 2)ans-=BigMod(2,cnt[0]+cnt[2]);
            temp=dp[a[i]-1];
            temp=(temp*BigMod(2,cnt[a[i]]))%mod;
            temp=(temp*BigMod(2,cnt[a[i]+2]))%mod;
            ans += temp;
            if(ans >= mod)ans -= mod;
        }
        ans %= mod;
        if(ans < 0)ans += mod;
        cout << ans << '\n';
    }
    return 0;
}