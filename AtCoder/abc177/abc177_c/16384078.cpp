#include<bits/stdc++.h>

using namespace std;

const int N=2e5;
long long a[N+2],sum[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    long long x,ans=0,mod=1e9+7;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]=(sum[i-1]+a[i])%mod;
    }
    for(i=1;i<n;i++)
    {
        x=(sum[n]-sum[i]+mod)%mod;
        ans+=x*a[i];
        ans%=mod;
    }
    cout << ans;
    return 0;
}
