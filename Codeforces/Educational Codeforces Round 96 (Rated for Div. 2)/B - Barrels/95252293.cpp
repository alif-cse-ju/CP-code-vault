#include<bits/stdc++.h>
 using namespace std;
 long long a[200002];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        ans=0;
        for(i=n;i>=n-k;i--)ans+=a[i];
        cout << ans << '\n';
    }
    return 0;
}