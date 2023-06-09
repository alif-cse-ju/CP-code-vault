#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,y,a[505],b[505];
    cin >> t;
    while(t--)
    {
        x=y=0;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)
        {
            cin >> b[i];
            if(b[i] == 0)++x;
            else ++y;
        }
        if(x  &&  y)cout << "Yes\n";
        else
        {
            for(i=2;i<=n;i++)
            {
                if(a[i] < a[i-1])break;
            }
            if(i > n)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;