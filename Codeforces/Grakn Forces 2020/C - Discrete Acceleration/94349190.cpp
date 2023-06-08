#include<bits/stdc++.h>
 using namespace std;
 int n,len;
long double a[100002];
 bool Check(long double T)
{
    int i;
    long double Ageche=0.0,Bgeche=0.0,speed=1.0,x=T,y;
    for(i=1;i<=n+1  &&  x > 0;i++)
    {
        y=min((a[i]-a[i-1])/speed,x);
        x-=y,Ageche+=speed*y;
        if(y > 0.0)speed++;
    }
    speed=1.00,x=T;
    for(i=n;i >= 0  &&  x > 0;i--)
    {
        y=min((a[i+1]-a[i])/speed,x);
        x-=y,Bgeche+=speed*y;
        if(y > 0.0)speed++;
    }
    return (Ageche+Bgeche >= len);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t;
    long double l,r,m,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> len;
        for(i=1;i<=n;i++)cin >> a[i];
        a[n+1]=len;
        l=0.1,r=1e9+5;
        for(i=1;i<=100;i++)
        {
            m=(l+r)/2.0;
            if(Check(m))r=ans=m;
            else l=m;
        }
        cout << fixed << setprecision(15) << ans << '\n';
    }
    return 0;
}