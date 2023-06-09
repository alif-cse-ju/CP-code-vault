#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
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
        sort(s.begin(),s.end());
        cout << s << '\n';
    }
    return 0;