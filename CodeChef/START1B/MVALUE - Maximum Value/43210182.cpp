#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=LLONG_MIN;
        sort(a+1,a+n+1);
        for(i=2;i<=n;i++)ans=max(ans,a[i]*a[i-1]+a[i]-a[i-1]);
        for(i=n;i>1;i--)ans=max(ans,a[i]*a[i-1]+a[i]-a[i-1]);
        cout << ans << '\n';
    }
    return 0;
}
//