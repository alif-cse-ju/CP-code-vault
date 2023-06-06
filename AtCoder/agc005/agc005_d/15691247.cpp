#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int fact[2002],mark[4002],dp[4002][2002][2];

int main()
{
    FAST();
    int i,j,m,n,x,ans=0,cnt=0,mod=924844033;
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        x=(n-i)/m+1;
        mark[cnt+1]=1,cnt+=x;
        mark[cnt+1]=1,cnt+=x;
    }
    dp[0][0][0]=1;
    for(i=1;i<=cnt;i++)
    {
        for(j=0;j<=n;j++)
        {
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%mod;
            if(!mark[i]  &&  j+1 <= n)dp[i][j+1][1]=dp[i-1][j][0];
        }
    }
    fact[0]=1;
    for(i=1;i<=n;i++)fact[i]=1LL*i*fact[i-1]%mod;
    for(i=0;i<=n;i++)
    {
        x=1LL*(dp[cnt][i][0]+dp[cnt][i][1])*fact[n-i]%mod;
        if(i & 1)ans+=mod-x;
        else ans+=x;
        if(ans >= mod)ans-=mod;
    }
    cout << ans;
    return 0;
}
