#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long x,y,lcm;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        lcm=(x*y)/__gcd(x,y);
        cout << (lcm/x)+(lcm/y)-2 << '\n';
    }
    return 0;
}