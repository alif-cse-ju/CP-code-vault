#include<bits/stdc++.h>
using namespace std;
const int M=4e2+5;
int n,mod;
long long fact[M],inv[M],pow2[M],choose[M][M],dp[M][M];
long long BigMod(long long val,long long pow)
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
void PreCompute()
    int i,j;
    fact[0]=inv[0]=1;
    for(i=1;i<=n;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=BigMod(fact[i],mod-2);
    }
    for(i=0;i<=n;i++)
    {
        pow2[i]=BigMod(2,i);
        for(j=0;j<=i;j++)choose[i][j]=((fact[i]*inv[j])%mod*inv[i-j])%mod;
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k;
    long long ans=0;
    cin >> n >> mod;
    PreCompute();
    dp[0][0]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            for(k=1;i+k<=n;k++)
            {
                dp[i+k+1][j+k]+=(dp[i][j]*pow2[k-1])%mod*choose[j+k][k];
                dp[i+k+1][j+k]%=mod;
            }
        }
    }
    for(i=0;i<=n;i++)ans=(ans+dp[n+1][i])%mod;
    cout << ans;
    return 0;
}