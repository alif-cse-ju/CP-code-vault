#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int a[M],b[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)cin >> x,a[x/2]=i;
        for(i=0;i<n;i++)cin >> b[i];
        for(i=1;i<n;i++)a[i]=min(a[i],a[i-1]);
        ans=INT_MAX;
        for(i=0;i<n;i++)ans=min(ans,i+a[b[i]/2-1]);
        cout << ans << '\n';
    }
    return 0;