#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,ans,a[N+2];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if((a[i] & a[j]) == a[i])++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}