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
const int M=1e3+5;
const int N=2e4+5;
const int mod=1e9+7;
int a[M],n;
ll dp[M][N];
ll DP(int cur,int sum)
    if(cur > n)return (sum == 0);
    ll &ans=dp[cur][(sum >= 0 ? sum : 10000+abs(sum))];
    if(ans > -1)return ans;
    ans=(sum == 0);
    ans += DP(cur+1,sum+a[cur]);
    ans += DP(cur+1,sum-a[cur]);
    return ans%=mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    ll ans=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=n;i++)ans=(ans+DP(i,0))%mod;
    ans -= n;
    if(ans < 0)ans += mod;
    cout << ans;
    return 0;
}