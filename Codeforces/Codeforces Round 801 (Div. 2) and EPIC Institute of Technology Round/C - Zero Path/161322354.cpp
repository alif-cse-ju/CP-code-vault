#pragma GCC optimize("Ofast")
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
const int sz = 1005;
int a[sz][sz],dp[sz][sz][2];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)cin >> a[i][j];
        }
        if(n%2 == m%2)
        {
            cout << "NO\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i == 1)dp[i][j][0]=dp[i][j-1][0], dp[i][j][1]=dp[i][j-1][1];
                else if(j == 1)dp[i][j][0]=dp[i-1][j][0], dp[i][j][1]=dp[i-1][j][1];
                else
                {
                    dp[i][j][0]=min(dp[i-1][j][0], dp[i][j-1][0]);
                    dp[i][j][1]=max(dp[i-1][j][1], dp[i][j-1][1]);
                }
                dp[i][j][0] += a[i][j], dp[i][j][1] += a[i][j];
            }
        }
        if(dp[n][m][0] <= 0  &&  dp[n][m][1] >= 0)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}