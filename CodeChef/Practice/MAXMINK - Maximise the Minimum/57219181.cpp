#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[42],b[42],dp[42][1602];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,k,K,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> K;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        for(i=0;i<=K;i++)
        {
            for(j=0;j<=40*K;j++)dp[i][j]=-2000;
        }
        dp[0][0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=K;j;j--)
            {
                for(k=a[i];k<=K*40;k++)dp[j][k]=max(dp[j][k], dp[j-1][k-a[i]]+b[i]);
            }
        }
        ans=0;
        for(i=1;i<=K*40;i++)ans=max(ans, min(i, dp[K][i]));
        cout << ans << '\n';
    }
    return 0;
}