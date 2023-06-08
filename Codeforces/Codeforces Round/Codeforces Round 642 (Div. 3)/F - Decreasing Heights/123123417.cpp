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
const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int m,n;
ll a[M][M],dp[M][M];
ll DP(const ll& val)
    if(a[0][0] < val)return LLONG_MAX;
    ll temp;
    int i,j;
    dp[0][0]=a[0][0]-val;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            temp=val+i+j;
            if(i || j)dp[i][j]=1e18;
            if(temp > a[i][j])continue;
            if(i)dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]-temp);
            if(j)dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]-temp);
        }
    }
    return dp[n-1][m-1];
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,j,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)cin >> a[i][j];
        }
        ans=LLONG_MAX;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)ans=min(ans,DP(a[i][j]-i-j));
        }
        cout << ans << '\n';
    }
    return 0;
}