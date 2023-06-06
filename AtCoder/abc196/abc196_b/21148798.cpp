#include<bits/stdc++.h>

using namespace std;

const int M=2e5+5;
const int N=5e2+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if(s[0] == '.')
    {
        cout << '0';
        return 0;
    }
    for(char c : s)
    {
        if(c == '.')break;
        cout << c;
    }
    return 0;
}
//