#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int cnt=0;
    cin >> s;
    for(char c : s)cnt+=c-'0';
    if(cnt%9)cout << "No";
    else cout << "Yes";
    return 0;
}