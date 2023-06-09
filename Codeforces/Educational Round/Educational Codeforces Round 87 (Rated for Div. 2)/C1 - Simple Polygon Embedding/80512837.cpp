#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int n,t;
    double ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=1/sin(PI/(2.0*(double)n));
        ans=ans*cos(PI/(2.0*(double)n));
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;