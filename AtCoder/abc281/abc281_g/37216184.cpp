// LUOGU_RID: 97114462
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mod;
int dp[510][510];
int pow2[1000010],c[510][510];
int qpow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int ycl[510][510];
signed main()
{
    cin>>n>>mod;
    pow2[0]=1; for(int i=1; i<=1e6; ++i) pow2[i]=pow2[i-1]*2%mod;
    c[0][0]=1;
    for(int i=1; i<=500; ++i) for(int j=0; j<=500; ++j) c[i][j]=(c[i-1][j]+(!j?0:c[i-1][j-1]))%mod;
    for(int i=1; i<=500; ++i) for(int j=1; j<=500; ++j) ycl[i][j]=qpow(pow2[i]-1,j);
    dp[1][1]=1;
    int ans=0;
    for(int i=2; i<=n-1; ++i)
    {
        for(int j=1; j<i; ++j)
        {
            for(int k=1; k<=i-j; ++k)
            {
                dp[i][j]=(dp[i][j]+dp[i-j][k]*ycl[k][j])%mod;
            }
            dp[i][j]=dp[i][j]*c[i-1][j]%mod*pow2[j*(j-1)/2]%mod;
            if(i==n-1) ans=(ans+dp[i][j]*(pow2[j]-1+mod))%mod;
        }
    }
    cout<<ans;
    return 0;
}