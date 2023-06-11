#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,a[3];
    long double s;
    cin >> t;
    while(t--)
    {
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        if(a[0]+a[1] <= a[2])cout << "NO\n";
        else
        {
            cout << "YES ";
            s=(a[0]+a[1]+a[2])/2;
            cout << fixed << setprecision(5) << sqrt(s*(s-a[0])*(s-a[1])*(s-a[2])) << '\n';
        }
    }
    return 0;
}