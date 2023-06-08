#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
int a[N],b[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,x,ans=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x)ans+=a[i];
        else b[i]=a[i];
        b[i]+=b[i-1];
    }
    x=0;
    for(i=k;i<=n;i++)x=max(x,b[i]-b[i-k]);
    cout << ans+x;
    return 0;
}