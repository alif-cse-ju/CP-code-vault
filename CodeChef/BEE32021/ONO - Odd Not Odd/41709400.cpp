#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,cnt;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cnt=0;
        for(char c : s)
        {
            if((c-'0') & 1)++cnt;
        }
        if(cnt < 2)cout << "-1\n";
        else
        {
            if(cnt & 1)cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}