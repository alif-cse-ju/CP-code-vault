#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int U=0,L=0,D=0,R=0;
    cin >> s;
    for(char c : s)
    {
        if(c == 'U')++U;
        else if(c == 'D')++D;
        else if(c == 'L')++L;
        else ++R;
    }
    if(U == D  &&  L == R)cout << "true";
    else cout << "false";
    return 0;
}