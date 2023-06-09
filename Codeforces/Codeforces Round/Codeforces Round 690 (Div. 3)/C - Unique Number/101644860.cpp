#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,x;
    string ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans="",x=9;
        while(x > 0)
        {
            if(n >= x)ans+=('0'+x),n-=x;
            x--;
        }
        if(n > 0)cout << "-1\n";
        else
        {
            reverse(ans.begin(),ans.end());
            cout << ans << '\n';
        }
    }
    return 0;