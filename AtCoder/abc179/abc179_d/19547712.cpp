#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int mod=998244353;

int l[12],r[12];
long long dp[N],cum[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n,x,y;
    cin >> n >> k;
    for(i=1;i<=k;i++)cin >> l[i] >> r[i];
    cum[0]=1;
    n--;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i-l[j] < 0)continue;
            x=max(0,i-r[j]),y=i-l[j];
            dp[i]+=(((cum[y]-(x == 0 ? 0 : cum[x-1]))%mod)+mod)%mod;
            dp[i]%=mod;
        }
        cum[i]=(cum[i-1]+dp[i])%mod;
    }
    cout << dp[n];
    return 0;
}