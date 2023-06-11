#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        for(char &c : s)c-=2;
        cout << s << '\n';
    }
    return 0;
}