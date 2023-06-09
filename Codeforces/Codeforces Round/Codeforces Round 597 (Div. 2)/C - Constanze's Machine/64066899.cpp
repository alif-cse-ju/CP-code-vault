#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int i,l,dp[100002];
    const int mod=1e9+7;
    cin >> s;
    l=s.size();
    dp[0]=dp[1]=1;
    if(s[0] == 'w'  ||  s[0] == 'm')
    {
        cout << 0;
        return 0;
    }
    for(i=2;i<=l;i++)
    {
        if(s[i-1] == 'w'  ||  s[i-1] == 'm')
        {
            cout << 0;
            return 0;
        }
        if(s[i-1] == s[i-2]  &&  (s[i-1] == 'u'  ||  s[i-1] == 'n'))dp[i]=(dp[i-1]+dp[i-2])%mod;
        else dp[i]=dp[i-1];
    }
    cout << dp[l];
    return 0;