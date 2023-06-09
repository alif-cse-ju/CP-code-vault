#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t,x,y;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        x=y=0;
        for(char c : s)
        {
            if(c == '0')++x;
            else ++y;
        }
        x=min(x,y);
        if(x & 1)cout << "DA\n";
        else cout << "NET\n";
    }
    return 0;