#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[102],b[102],_tm[102];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i] >> b[i];
        for(i=1;i<=n;i++)cin >> _tm[i];
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans+=(a[i]-b[i-1])+_tm[i];
            if(i < n)
            {
                ans+=(b[i]-a[i]+1)/2;
                if(ans < b[i])ans=b[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;