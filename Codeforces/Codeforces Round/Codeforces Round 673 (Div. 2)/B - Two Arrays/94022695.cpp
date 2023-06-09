#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,T;
    bool flag;
    cin >> t;
    while(t--)
    {
        cin >> n >> T;
        for(i=1;i<=n;i++)cin >> a[i];
        if(T & 1)
        {
            for(i=1;i<=n;i++)
            {
                if(a[i] <= T/2)cout << "0 ";
                else cout << "1 ";
            }
        }
        else
        {
            flag=0;
            for(i=1;i<=n;i++)
            {
                if(a[i] < T/2)cout << "0 ";
                else if(a[i] > T/2)cout << "1 ";
                else
                {
                    if(flag)cout << "0 ";
                    else cout << "1 ";
                    flag=!flag;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}