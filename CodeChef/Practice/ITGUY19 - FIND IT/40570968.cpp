#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,x,xr;
    cin >> t;
    while(t--)
    {
        cin >> n;
        xr=0;
        while(n--)
        {
            cin >> x;
            xr ^= x;
        }
        cout << xr << '\n';
    }
    return 0;
}