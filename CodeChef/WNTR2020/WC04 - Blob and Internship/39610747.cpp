#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N],dp1[N],dp2[N],dp3[N],dp4[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    dp1[0]=dp2[1]=dp3[2]=dp4[3]=-1e7;
    for(i=1;i<=n;i++)dp1[i]=max(dp1[i-1],-a[i]);
    for(i=2;i<=n;i++)dp2[i]=max(dp2[i-1],dp1[i-1]+a[i]);
    for(i=3;i<=n;i++)dp3[i]=max(dp3[i-1],dp2[i-1]-a[i]);
    for(i=4;i<=n;i++)dp4[i]=max(dp4[i-1],dp3[i-1]+a[i]);
    cout << dp4[n];
    return 0;
}