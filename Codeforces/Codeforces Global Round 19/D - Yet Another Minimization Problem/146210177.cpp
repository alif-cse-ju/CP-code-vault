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
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 102;
int n,a[sz],b[sz],dp[sz][sz*sz],sum[sz];
int DP(int i,int curSum)
    if(i > n)return 0;
    int &ans=dp[i][curSum];
    if(ans > -1)return ans;
    ans=a[i]*curSum+b[i]*(sum[i-1]-curSum)+DP(i+1,curSum+a[i]);
    ans=min(ans, a[i]*(sum[i-1]-curSum)+b[i]*curSum+DP(i+1,curSum+b[i]));
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        ans=0;
        for(i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+a[i]+b[i];
            ans += (n-1)*(a[i]*a[i] + b[i]*b[i]);
            for(j=0;j<=n*100;j++)dp[i][j]=-1;
        }
        cout << ans+2*DP(1,0) << '\n';
    }
    return 0;
}