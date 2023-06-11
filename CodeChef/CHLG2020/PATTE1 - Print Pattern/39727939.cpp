#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    long long x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x=1,y=3;
        cout << "1 ";
        for(i=2;i<=n;i++)
        {
            x+=y;
            y*=2;
            cout << x << ' ';
        }
        cout << '\n';
        x=2,y=3;
        cout << "2 ";
        for(i=2;i<=n;i++)
        {
            x+=y;
            y*=2;
            cout << x << ' ';
        }
        cout << '\n';
        x=1,y=3;
        for(i=1;i<=n;i++)
        {
            x+=y;
            y*=2;
            cout << x << ' ';
        }
        cout << '\n';
        x=0,y=3;
        for(i=1;i<=n;i++)
        {
            x+=y;
            if(i > 1)y*=2;
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}