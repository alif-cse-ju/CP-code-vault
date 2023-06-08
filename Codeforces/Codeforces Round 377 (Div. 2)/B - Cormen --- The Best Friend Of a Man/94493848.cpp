#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,x,ans=0,a[505];
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=2;i<=n;i++)
    {
        x=max(0,k-a[i]-a[i-1]);
        ans+=x,a[i]+=x;
    }
    cout << ans << '\n';
    for(i=1;i<=n;i++)cout << a[i] << ' ';
    return 0;
}