#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
long long a[N],b[N],c[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n1,n2,n3;
    long long ans=0;
    cin >> n1 >> n2 >> n3;
    for(i=1;i<=n1;i++)cin >> a[i];
    for(i=1;i<=n2;i++)cin >> b[i];
    for(i=1;i<=n3;i++)cin >> c[i];
    sort(a+1,a+n1+1);
    sort(b+1,b+n2+1);
    sort(c+1,c+n3+1);
    for(i=n1-1;i>1;i--)a[i]+=a[i+1];
    for(i=n2-1;i>1;i--)b[i]+=b[i+1];
    for(i=n3-1;i>1;i--)c[i]+=c[i+1];
    n1=min(2,n1);
    n2=min(2,n2);
    n3=min(2,n3);
    if(n1 == 2)ans=max(ans,b[1]+b[2]+c[1]+c[2]-a[1]-a[2]);
    if(n2 == 2)ans=max(ans,a[1]+a[2]+c[1]+c[2]-b[1]-b[2]);
    if(n3 == 2)ans=max(ans,a[1]+a[2]+b[1]+b[2]-c[1]-c[2]);
    ans=max(ans,a[2]+b[2]+c[1]+c[2]-a[1]-b[1]);
    ans=max(ans,a[2]+b[1]+b[2]+c[2]-a[1]-c[1]);
    ans=max(ans,a[1]+a[2]+b[2]+c[2]-b[1]-c[1]);
    a[1]+=a[2],b[1]+=b[2],c[1]+=c[2];
    ans=max(ans,a[1]+b[1]-c[1]);
    ans=max(ans,a[1]+c[1]-b[1]);
    ans=max(ans,b[1]+c[1]-a[1]);
    cout << ans;
    return 0;
}
//