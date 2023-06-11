#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long e,o,n,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        e=n/2,o=(n+1)/2;
        y=(o*(o-1)) + (e*(e-1));
        if(x == y)cout << "0 Null\n";
        else if(x > y)cout << x-y << " Loss\n";
        else cout << y-x << " Profit\n";
    }
    return 0;
}