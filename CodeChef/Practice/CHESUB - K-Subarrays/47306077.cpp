#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long dp[105],mx[105],sum[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)
        {
            cin >> sum[i];
            sum[i]+=sum[i-1];
        }
        dp[0]=mx[0]=0;
        for(i=1;i<=k;i++)dp[i]=mx[i]=LLONG_MIN;
        for(i=1;i<=n;i++)
        {
            for(j=k;j;j--)
            {
                if(mx[j-1] > LLONG_MIN)
                {
                    dp[j]=max(dp[j],mx[j-1]+sum[i]*j);
                    mx[j]=max(mx[j],dp[j]-sum[i]*(j+1));
                }
            }
            mx[0]=max(mx[0],dp[0]-sum[i]);
        }
        cout << dp[k] << '\n';
    }
    return 0;
}