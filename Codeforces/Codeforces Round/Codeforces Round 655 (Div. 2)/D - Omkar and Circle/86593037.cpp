#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL a[200005],fr[200005],rv[200005];
int main()
    FAST();
    int i,n;
    LL ans=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    fr[1]=a[1];
    for(i=2;i<=n;i++)fr[i]+=fr[i-2]+a[i];
    for(i=n;i>0;i--)rv[i]+=rv[i+2]+a[i];
    for(i=2;i<=n;i++)ans=max(ans,fr[i-1]+rv[i]);
    cout << max(ans,fr[n]);
    return 0;