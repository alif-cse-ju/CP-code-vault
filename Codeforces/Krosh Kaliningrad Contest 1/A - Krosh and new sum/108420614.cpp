#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)a[i]*=a[i];
    long long ans=0;
    for(i=1;i<=n;i++)
    {
        ans+=(i-1)*(a[i]%mod);
        ans-=a[i-1];
        ans%=mod;
        a[i]+=a[i-1];
        a[i]%=mod;
    }
    if(ans < 0)ans+=mod;
    cout << ans;
    return 0;