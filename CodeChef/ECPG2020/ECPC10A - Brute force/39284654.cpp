#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,xr,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                xr=a[i] ^ a[j];
                if(xr > a[i]  &&  xr > a[j])++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}