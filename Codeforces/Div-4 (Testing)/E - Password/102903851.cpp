#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
char s[N];
long long dp[N][10];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,l;
    cin >> s+1;
    l=strlen(s+1);
    for(i=1;i<10;i++)dp[0][i]=1;
    for(i=1;i<=l;i++)
    {
        if(s[i] >= '1'  &&  s[i] <= '9')dp[i][s[i]-'0']=dp[i-1][s[i]-'0'];
        else
        {
            for(j=1;j<10;j++)dp[i][j]=dp[i-1][j];
        }
        for(j=2;j<10;j++)
        {
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    if(!dp[l][9])cout << "-1";
    else cout << dp[l][9];
    return 0;