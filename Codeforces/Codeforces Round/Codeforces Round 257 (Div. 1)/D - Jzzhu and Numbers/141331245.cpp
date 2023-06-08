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
const int mod=1e9+7;
const int l = (1 << 20);
ll dp[l],pw[l];
void PreCal()
    pw[0]=1;
    for(int i=1;i<l;i++)pw[i]=(pw[i-1]*2)%mod;
void DP()
    int i,mask;
    for(i=0;i<20;i++)
    {
        for(mask=0;mask < l;mask++)
        {
            if(!((mask >> i) & 1))dp[mask] += dp[mask ^ (1 << i)];
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,n,x;
    PreCal();
    cin >> n;
    for(i=0;i<n;i++)cin >> x, ++dp[x];
    DP();
    for(i=0;i<l;i++)
    {
        if(__builtin_popcount(i) & 1)ans -= pw[dp[i]];
        else ans += pw[dp[i]];
        if(ans < 0)ans += mod;
        if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}