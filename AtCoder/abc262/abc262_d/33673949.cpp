#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;

int n;
ll a[102],dp[102][102][102],m;

ll DP(int i,int rem,int nibo)
{
    if(!nibo)return rem == 0;
    if(i > n)return 0;
    ll &ans=dp[i][rem][nibo];
    if(ans > -1)return ans;
    ans=DP(i+1,rem,nibo) + DP(i+1,(rem+a[i])%m,nibo-1);
    if(ans >= mod)ans -= mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<i;k++)
            {
                for(int l=1;l<=i;l++)dp[j][k][l]=-1;
            }
        }
        m=i, ans += DP(1,0,i);
        if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}
