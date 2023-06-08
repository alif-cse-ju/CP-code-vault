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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
bool dp[M][452];
ll a[M],sum[M],val[M][452];
int DP(const int& n)
    int i,j;
    val[n+1][1]=0;
    for(i=n;i;i--)dp[i][1]=1, val[i][1]=max(a[i],val[i+1][1]);
    for(j=2; ;j++)
    {
        for(i=n;i;i--)
        {
            dp[i][j]=val[i][j]=0;
            if(i+j > n)continue;
            if(sum[i]-sum[i+j] < val[i+j][j-1])dp[i][j]=1, val[i][j]=sum[i]-sum[i+j];
            dp[i][j] |= dp[i+1][j];
            val[i][j]=max(val[i][j], val[i+1][j]);
        }
        if(!dp[1][j])return j-1;
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=n,sum[n+1]=0;i;i--)sum[i] = sum[i+1]+a[i];
        cout << DP(n) << '\n';
    }
    return 0;
}