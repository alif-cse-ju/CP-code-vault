#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(__gcd(a,b) == 1)cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;