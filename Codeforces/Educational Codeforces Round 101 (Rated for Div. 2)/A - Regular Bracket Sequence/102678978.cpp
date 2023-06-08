#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=(int)s.size();
        if(l%2 == 0  &&  s[0] != ')'  &&  s.back() != '(')cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;