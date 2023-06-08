#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,l,m,n,r,ans,mn,mx;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    l=1,r=n;
    while(l <= r)
    {
        m=(l+r) >> 1;
        for(i=1;i<=n;i++)
        {
            if(a[i] >= m)b[i]=1;
            else b[i]=-1;
            b[i]+=b[i-1];
        }
        mn=mx=0;
        for(i=k;i<=n;i++)
        {
            mn=min(mn,b[i-k]);
            mx=max(mx,b[i]-mn);
        }
        if(mx)ans=m,l=m+1;
        else r=m-1;
    }
    cout << ans;
    return 0;