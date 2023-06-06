#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    string s;
    cin >> s;
    if(s[0] == 'R'  &&  s[1] == 'R'  &&  s[2] == 'R')cout << "3";
    else if(s[0] == 'R'  &&  s[1] == 'R')cout << "2";
    else if(s[1] == 'R'  &&  s[2] == 'R')cout << "2";
    else if(s[0] == 'R'  ||  s[1] == 'R'  ||  s[2] == 'R')cout << "1";
    else cout << "0";
    return 0;
}
