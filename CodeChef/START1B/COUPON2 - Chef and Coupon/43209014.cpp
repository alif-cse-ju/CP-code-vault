#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[3],b[3],c,d,i,t;
    cin >> t;
    while(t--)
    {
        cin >> d >> c;
        for(i=0;i<3;i++)cin >> a[i];
        for(i=0;i<3;i++)cin >> b[i];
        for(i=2;i;i--)a[i-1]+=a[i],b[i-1]+=b[i];
        if(a[0] >= 150  &&  b[0] >= 150)
        {
            if(2*d > c)cout << "YES\n";
            else cout << "NO\n";
        }
        else if(a[0] >= 150  ||  b[0] >= 150)
        {
            if(d > c)cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
//