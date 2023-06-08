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
ll dp[M],pw[N];
int a[M],cnt[M];
void PreCal()
    pw[0]=1;
    for(int i=1;i<N;i++)pw[i]=(pw[i-1]*2)%mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,temp;
    int i,n,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<=n+2;i++)cnt[i]=dp[i]=0;
        for(i=1;i<=n;i++)cin >> a[i], ++cnt[a[i]];
        ans=pw[cnt[0]+cnt[2]]+pw[cnt[1]]-2;
        for(i=1;i<=n;i++)
        {
            --cnt[a[i]];
            if(!a[i])dp[0]=(dp[0]*2ll+1)%mod;
            else dp[a[i]]=(dp[a[i]-1]+dp[a[i]]+dp[a[i]])%mod;
            if(!a[i])continue;
            if(a[i] == 2)ans-=pw[cnt[0]+cnt[2]];
            temp=dp[a[i]-1];
            temp=(temp*pw[cnt[a[i]]])%mod;
            temp=(temp*pw[cnt[a[i]+2]])%mod;
            ans += temp;
            if(ans >= mod)ans -= mod;
        }
        ans %= mod;
        if(ans < 0)ans += mod;
        cout << ans << '\n';
    }
    return 0;
}