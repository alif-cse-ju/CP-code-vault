#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,ans,a[55];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=INT_MAX;
        sort(a+1,a+n+1);
        for(i=2;i<=n;i++)ans=min(ans,a[i]-a[i-1]);
        cout << ans << '\n';
    }
    return 0;