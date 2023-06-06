#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int n;
    string s;
    map<string,int>mp;
    cin >> n;
    while(n--)
    {
        cin >> s;
        ++mp[s];
    }
    cout << "AC x " << mp["AC"] << '\n';
    cout << "WA x " << mp["WA"] << '\n';
    cout << "TLE x " << mp["TLE"] << '\n';
    cout << "RE x " << mp["RE"] << '\n';
    return 0;
}
