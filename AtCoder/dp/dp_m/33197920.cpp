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
const int mod=1e9+7;

const int sz = 102;

int a[sz],dp[sz][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=k;j++)
            {
                    dp[i-1][j] += dp[i-1][j-1];
                    if(dp[i-1][j] >= mod)dp[i-1][j] -= mod;
            }

            for(int j=0;j<=k;j++)
            {
                    dp[i][j] = dp[i-1][j] - (j-a[i]-1 >= 0 ? dp[i-1][j-a[i]-1] : 0);
                    if(dp[i][j] < 0)dp[i][j] += mod;
                    else if(dp[i][j] >= mod)dp[i][j] -= mod;
            }
    }
    cout << dp[n][k];
    return 0;
}