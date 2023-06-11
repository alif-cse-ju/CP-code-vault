#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)
        {
            if(a[i] <= n)b[i]=a[i]+a[a[i]];
            else
            {
                x=a[i];
                while(x >= n)x/=2;
                b[i]=a[n-x];
            }
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}