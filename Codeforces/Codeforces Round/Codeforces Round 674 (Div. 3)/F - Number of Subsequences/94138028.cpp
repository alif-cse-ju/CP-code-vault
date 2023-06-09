#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
const int mod=1e9+7;
string s,abc="abc";
long long l,dp[N][5];
long long DP(int idx,int posABC)
    if(idx == l)return posABC == 3;
    long long &ans=dp[idx][posABC];
    if(ans > -1)return ans;
    ans=0;
    if(s[idx] != '?')
    {
        if(posABC < 3  &&  s[idx] == abc[posABC])
        {
            ans+=DP(idx+1,posABC+1);
            ans%=mod;
        }
        ans+=DP(idx+1,posABC);
        ans%=mod;
    }
    else
    {
        for(char c : abc)
        {
            if(posABC < 3  &&  c == abc[posABC])
            {
                ans+=DP(idx+1,posABC+1);
                ans%=mod;
            }
            ans+=DP(idx+1,posABC);
            ans%=mod;
        }
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> l >> s;
    memset(dp,-1,sizeof(dp));
    cout << DP(0,0);
    return 0;
}