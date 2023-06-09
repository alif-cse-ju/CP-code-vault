#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n;
    long long ans=0,a[505];
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            for(k=j;k<=n;k++)ans=max(ans,(a[i] | a[j] | a[k]));
        }
    }
    cout << ans;
    return 0;