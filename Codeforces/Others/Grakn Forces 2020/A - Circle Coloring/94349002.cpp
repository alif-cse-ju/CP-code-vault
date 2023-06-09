#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,a[102],b[102],c[102];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        for(i=1;i<=n;i++)cin >> c[i];
        x=a[1];
        cout << a[1];
        for(i=2;i<n;i++)
        {
            if(a[i] != x)
            {
                cout << ' ' << a[i];
                x=a[i];
            }
            else if(b[i] != x)
            {
                cout << ' ' << b[i];
                x=b[i];
            }
            else
            {
                cout << ' ' << c[i];
                x=c[i];
            }
        }
        if(a[i] != x  &&  a[i] != a[1])
            {
                cout << ' ' << a[i];
                x=a[i];
            }
            else if(b[i] != x  &&  b[i] != a[1])
            {
                cout << ' ' << b[i];
                x=b[i];
            }
            else
            {
                cout << ' ' << c[i];
                x=c[i];
            }
        cout << '\n';
    }
    return 0;
}