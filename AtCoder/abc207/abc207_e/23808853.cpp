#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=3e3+5;
const int mod=1e9+7;

ll a[N],dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,j,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i],a[i]+=a[i-1];
    dp[1][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=n;j;j--)
        {
            dp[j+1][a[i]%(j+1)]+=dp[j][a[i]%j];
            dp[j+1][a[i]%(j+1)]%=mod;
            if(i == n)ans=(ans+dp[j][a[n]%j])%mod;
        }
    }
    cout << ans;
    return 0;
}