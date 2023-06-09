#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int l,t,cnt0,cnt1;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        cnt0=cnt1=0;
        for(char c : s)
        {
            if(c == '0')++cnt0;
            else ++cnt1;
        }
        if(cnt0 > cnt1)
        {
            while(l--)cout << '0';
        }
        else
        {
            while(l--)cout << '1';
        }
        cout << '\n';
    }
    return 0;