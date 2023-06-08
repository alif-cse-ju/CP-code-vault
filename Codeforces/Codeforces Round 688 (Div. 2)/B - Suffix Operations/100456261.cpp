#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,mx;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0;
        for(i=2;i<=n;i++)ans+=abs(a[i]-a[i-1]);
        mx=max(abs(a[1]-a[2]),abs(a[n-1]-a[n]));
        for(i=2;i<n;i++)mx=max(mx,abs(a[i-1]-a[i])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]));
        cout << ans-mx << '\n';
    }
    return 0;