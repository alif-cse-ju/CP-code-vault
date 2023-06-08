#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int mod=1e9+7;
long long a[N],cnt[N],dp[N][N];
void PreCal(const int& n,const int& k)
    int i,j;
    for(i=1;i<=n;i++)dp[i][0]=1;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++)dp[j][i]=(dp[j-1][i-1]+dp[j+1][i-1])%mod;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            cnt[i]+=dp[i][j]*dp[i][k-j];
            cnt[i]%=mod;
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,q,x,y;
    long long ans=0;
    cin >> n >> k >> q;
    PreCal(n,k);
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        ans+=a[i]*cnt[i];
        ans%=mod;
    }
    while(q--)
    {
        cin >> x >> y;
        ans=(ans-a[x]*cnt[x])%mod;
        if(ans < 0)ans+=mod;
        a[x]=y;
        ans=(ans+a[x]*cnt[x])%mod;
        cout << ans << '\n';
    }
    return 0;
}
//