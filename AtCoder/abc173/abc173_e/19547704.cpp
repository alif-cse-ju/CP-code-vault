#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int mod=1e9+7;

long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,l,n,r;
    long long x,y,ans=1;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    if(a[1] >= 0)
    {
        reverse(a+1,a+n+1);
        for(i=1;i<=k;i++)ans=(ans*a[i])%mod;
    }
    else if(a[n] < 0)
    {
        if(k & 1)reverse(a+1,a+n+1);
        for(i=1;i<=k;i++)ans=(ans*a[i])%mod;
    }
    else
    {
        l=1,r=n;
        if(k & 1)ans=(ans*a[r--])%mod,k--;
        for(i=1;i<k;i+=2)
        {
            x=(a[l]*a[l+1]);
            y=(a[r]*a[r-1]);
            if(x >= y)
            {
                l+=2;
                x%=mod;
                ans=(ans*x)%mod;
            }
            else
            {
                r-=2;
                y%=mod;
                ans=(ans*y)%mod;
            }
        }
    }
    if(ans < 0)ans+=mod;
    cout << ans;
    return 0;
}