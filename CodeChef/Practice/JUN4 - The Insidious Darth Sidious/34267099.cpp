#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,j,n;
    cin >> n;
    int dp[n+2];
    dp[1]=0;
    for(i=2;i<=n;i++)
    {
        dp[i]=i;
        for(j=i-1;j>0;j--)
        {
            if(i%j == 0)dp[i]=min(dp[i],dp[j]+i/j);
        }
    }
    cout << dp[n];
    return 0;
}