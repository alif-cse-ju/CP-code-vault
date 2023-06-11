#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cnt=0;
        for(char c : s)cnt+=(c == '#');
        cout << cnt << '\n';
    }
    return 0;
}
//