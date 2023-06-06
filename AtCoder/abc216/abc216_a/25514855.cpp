#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int l=(int)s.size();
    for(int i=0;i<l-2;i++)cout << s[i];
    if(s[l-1] <= '2')cout << '-';
    else if(s[l-1] >= '7')cout << '+';
    return 0;
}
