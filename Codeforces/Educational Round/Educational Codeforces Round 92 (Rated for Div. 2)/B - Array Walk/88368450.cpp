#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,k,n,t,z;
    LL ans,x,y,a[100002],sum[100002];
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> k >> z;
        sum[0]=0;
        for(i=1;i<=n;i++)cin >> a[i],sum[i]=sum[i-1]+a[i];
        for(i=2;i<=k+1;i++)
        {
            x=min(z,(k-i+2)/2),y=min(z,(k-i+1)/2);
            ans=max(ans,x*a[i-1]+y*a[i]+sum[k-x-y+1]);
        }
        cout << ans << '\n';
    }
    return 0;