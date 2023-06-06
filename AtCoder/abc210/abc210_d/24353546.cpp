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
const int N=2e5+5;
const int mod=1e9+7;

ll a[M][M],dp1[M][M],dp2[M][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n;
    ll c,ans=LLONG_MAX;
    cin >> n >> m >> c;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cin >> a[i][j];
    }
    for(i=1;i<=n;i++)dp1[i][0]=1e18;
    for(i=1;i<=m;i++)dp1[0][i]=1e18;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)dp1[i][j]=min({a[i][j],dp1[i-1][j]+c,dp1[i][j-1]+c});
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dp2[i][j]=min(dp1[i-1][j],dp1[i][j-1])+a[i][j]+c;
            ans=min(ans,dp2[i][j]);
        }
    }
    for(i=1;i<=n;i++)dp1[i][m+1]=1e18;
    for(i=1;i<=n;i++)
    {
        for(j=m;j;j--)dp1[i][j]=min({a[i][j],dp1[i-1][j]+c,dp1[i][j+1]+c});
    }
    for(i=1;i<=n;i++)
    {
        for(j=m;j;j--)
        {
            dp2[i][j]=min(dp1[i-1][j],dp1[i][j+1])+a[i][j]+c;
            ans=min(ans,dp2[i][j]);
        }
    }
    cout << ans;
    return 0;
}
