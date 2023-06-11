#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long a,b,n;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        n%=3;
        if(n == 0)cout << a << '\n';
        else if(n == 1)cout << b << '\n';
        else cout << (a^b) << '\n';
    }
    return 0;
}