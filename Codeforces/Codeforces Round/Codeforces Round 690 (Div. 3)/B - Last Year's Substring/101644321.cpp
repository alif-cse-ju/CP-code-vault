#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        if(l < 4)cout << "NO\n";
        else if(s[0] == '2'  &&  s[1] == '0'  &&  s[2] == '2'  &&  s[3] == '0')cout << "YES\n";
        else if(s[l-4] == '2'  &&  s[l-3] == '0'  &&  s[l-2] == '2'  &&  s[l-1] == '0')cout << "YES\n";
        else if(s[0] == '2'  &&  s[1] == '0'  &&  s[2] == '2'  &&  s[l-1] == '0')cout << "YES\n";
        else if(s[0] == '2'  &&  s[l-3] == '0'  &&  s[l-2] == '2'  &&  s[l-1] == '0')cout << "YES\n";
        else if(s[0] == '2'  &&  s[1] == '0'  &&  s[l-2] == '2'  &&  s[l-1] == '0')cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;