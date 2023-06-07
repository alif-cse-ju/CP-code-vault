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

const int M=1e5+5;
const int N=2e6+5;
//const int mod=1e9+7;

const int sz = 502;

int a[sz],dp[2][sz][sz];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int b,m,mod,n; cin >> n >> m >> b >> mod;
    for(int i=1;i<=n;i++)cin >> a[i];

    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
            int par=(i & 1);
            for(int j=0;j<=m;j++)
            {
                    for(int k=0;k<=b;k++)
                    {
                            dp[par][j][k] = dp[1-par][j][k];
                            if(j  &&  k>=a[i])dp[par][j][k] += dp[par][j-1][k-a[i]];

                            if(dp[par][j][k] >= mod)dp[par][j][k] -= mod;
                    }
            }
    }

    int ans=0;
    for(int i=0;i<=b;i++)
    {
            ans += dp[n%2][m][i];
            if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}