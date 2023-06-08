#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t,x,a[6],c[4];
    cin >> t;
    while(t--)
    {
        for(i=1;i<4;i++)cin >> c[i];
        for(i=1;i<6;i++)cin >> a[i];
        for(i=1;i<4;i++)
        {
            x=min(a[i],c[i]);
            a[i]-=x,c[i]-=x;
        }
        x=min(c[1],a[4]);
        a[4]-=x,c[1]-=x;
        x=min(c[2],a[5]);
        a[5]-=x,c[2]-=x;
        x=min(c[3],a[4]);
        a[4]-=x,c[3]-=x;
        x=min(c[3],a[5]);
        a[5]-=x,c[3]-=x;
        for(i=1;i<6;i++)
        {
            if(a[i] > 0)break;
        }
        if(i == 6)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}