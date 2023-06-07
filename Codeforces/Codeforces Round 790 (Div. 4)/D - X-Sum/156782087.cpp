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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll a[205][205],sum1[205][205],sum2[205][205],sum3[205][205],sum4[205][205];
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
            for(int i=0;i<=n+1;i++)
            {
                    for(int j=0;j<=m+1;j++)
                    {
                            sum1[i][j]=0;
                            sum2[i][j]=0;
                            sum3[i][j]=0;
                            sum4[i][j]=0;
                    }
            }
            for(int i=1;i<=n;i++)
            {
                    for(int j=1;j<=m;j++)sum1[i][j]=sum1[i-1][j-1]+a[i][j];
            }
            for(int i=1;i<=n;i++)
            {
                    for(int j=m;j;j--)sum2[i][j]=sum2[i-1][j+1]+a[i][j];
            }
            for(int i=n;i;i--)
            {
                    for(int j=1;j<=m;j++)sum3[i][j]=sum3[i+1][j-1]+a[i][j];
            }
            for(int i=n;i;i--)
            {
                    for(int j=m;j;j--)sum4[i][j]=sum4[i+1][j+1]+a[i][j];
            }
            ll ans=0;
            for(int i=1;i<=n;i++)
            {
                    for(int j=1;j<=m;j++)ans=max(ans, sum1[i][j]+sum2[i][j]+sum3[i][j]+sum4[i][j]-3*a[i][j]);
            }
            cout << ans << '\n';
    }
    return 0;
}