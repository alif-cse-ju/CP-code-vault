#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int a[N],b[N],forL[N],forR[N],revL[N],revR[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,r,ans=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i] >> b[i];
    forL[0]=revL[n+1]=0,forR[0]=revR[n+1]=mod;
    for(i=1;i<=n;i++)
    {
        forL[i]=max(forL[i-1],a[i]);
        forR[i]=min(forR[i-1],b[i]);
    }
    for(i=n;i>0;i--)
    {
        revL[i]=max(revL[i+1],a[i]);
        revR[i]=min(revR[i+1],b[i]);
    }
    for(i=1;i<=n;i++)
    {
        l=max(forL[i-1],revL[i+1]);
        r=min(forR[i-1],revR[i+1]);
        ans=max(ans,max(0,r-l));
    }
    cout << ans;
    return 0;