#include<bits/stdc++.h>
 using namespace std;
 const int N=5e3+5;
 int dp[N][N];
char a[N],b[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,la,lb,ans=0;
    cin >> la >> lb >> a+1 >> b+1;
    for(i=1;i<=la;i++)
    {
        for(j=1;j<=lb;j++)
        {
            if(a[i] == b[j])dp[i][j]=max(2,dp[i-1][j-1]+2);
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1])-1;
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}