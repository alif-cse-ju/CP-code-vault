#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if(s[0] == s[2])cout << "Won";
    else cout << "Lost";
    return 0;
}