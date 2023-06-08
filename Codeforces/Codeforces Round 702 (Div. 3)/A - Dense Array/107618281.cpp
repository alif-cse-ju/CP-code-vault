#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,a[55],ans,mn,mx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0;
        for(i=2;i<=n;i++)
        {
            mn=min(a[i],a[i-1]);
            mx=max(a[i],a[i-1]);
            while(mn*2 < mx)
            {
                mn*=2;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;