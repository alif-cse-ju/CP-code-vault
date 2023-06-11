#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int a[100005],cntf[100005],cntr[100005];
int main()
{
    FAST();
    int i,k,n,ans=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    cin >> k;
    for(i=1;i<=n;i++)cntf[i]=cntf[i-1]+a[i],cntr[n-i+1]=cntr[n-i+2]+a[n-i+1];
    for(i=0;i<=k   &&  i<=n;i++)ans=max(ans,cntf[i]+cntr[max(i+1,n-k+i+1)]);
    cout << ans;
    return 0;
}