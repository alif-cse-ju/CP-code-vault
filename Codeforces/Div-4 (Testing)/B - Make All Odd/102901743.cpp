#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int cnt0=0,cnt1=0;
    cin >> s;
    for(char c : s)
    {
        cnt0+=(c == '0');
        cnt1+=(c == '1');
    }
    if(cnt0 >= cnt1)
    {
        cnt0-=cnt1;
        cnt0%=4;
        if(!cnt0)cout << 'E';
        else if(cnt0 == 1)cout << 'S';
        else if(cnt0 == 2)cout << 'W';
        else cout << 'N';
    }
    else
    {
        cnt1-=cnt0;
        cnt1%=4;
        if(!cnt1)cout << 'E';
        else if(cnt1 == 1)cout << 'N';
        else if(cnt1 == 2)cout << 'W';
        else cout << 'S';
    }
    return 0;