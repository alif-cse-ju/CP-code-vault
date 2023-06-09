#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],fr[N],rv[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        fr[0]=rv[n+1]=0;
        for(i=1;i<=n;i++)
        {
            if(fr[i-1] <= a[i])fr[i]=a[i]-fr[i-1];
            else fr[i]=INT_MAX;
        }
        for(i=n;i;i--)
        {
            if(rv[i+1] <= a[i])rv[i]=a[i]-rv[i+1];
            else rv[i]=INT_MAX;
        }
        if(!fr[n]  ||  !rv[1])cout << "YES\n";
        else
        {
            flag=0;
            for(i=2;i<=n;i++)
            {
                if(a[i] >= fr[i-2])x=a[i]-fr[i-2];
                else x=INT_MIN;
                if(a[i-1] >= rv[i+1])y=a[i-1]-rv[i+1];
                else y=INT_MAX;
                if(x == y)flag=1;
            }
            if(flag)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
//