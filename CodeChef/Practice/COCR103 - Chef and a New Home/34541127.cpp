#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const LL mod=1e9+7;
LL dp[102][602][102];
int main()
{
    FAST();
    int i,j,k,l,n,s,t,ans,sum,a[102];
    cin >> t;
    while(t--)
    {
        sum=0;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i],sum+=a[i];
        cin >> s >> l;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=2*sum;j++)
            {
                for(k=0;k<=n;k++)dp[i][j][k]=0;
            }
        }
        dp[0][sum][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=-sum;j<=sum;j++)
            {
                for(k=0;k<=i;k++)
                {
                    dp[i][j+sum][k]=dp[i-1][j+sum][k];
                    if(j >= a[i]-sum)dp[i][j+sum][k]=(dp[i][j+sum][k]+dp[i-1][j+sum-a[i]][k])%mod;
                    if(j+a[i] <= sum)dp[i][j+sum][k]=(dp[i][j+sum][k]+dp[i-1][j+sum+a[i]][k-1])%mod;
                }
            }
        }
        l=min(l,n);
        if(s > sum)cout << "0\n";
        else
        {
            ans=0;
            for(i=0;i<=l;i++)ans=(ans+dp[n][s+sum][i])%mod;
            cout << ans << '\n';
        }
    }
    return 0;
}