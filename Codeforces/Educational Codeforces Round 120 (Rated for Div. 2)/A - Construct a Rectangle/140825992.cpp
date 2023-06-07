#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        if(a == b  &&  c%2 == 0)cout << "YES\n";
        else if(a == c  &&  b%2 == 0)cout << "YES\n";
        else if(b == c  &&  a%2 == 0)cout << "YES\n";
        else if(a+b == c  ||  a+c == b  ||  b+c == a)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;