#include<bits/stdc++.h>
using namespace std;
const int M=1e3+5;
const int mod=23102009;
char a[M],b[M];
int la,lb,dp[M][M],lcs[M][M];
void DP()
{
    int i,j;
    for(i=0;i<=la;i++)
    {
        for(j=0;j<=lb;j++)
        {
            if(!i  ||  !j)dp[i][j]=1;
            else
            {
                if(a[i] == b[j])
                {
                    dp[i][j]=dp[i-1][j-1];
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=0;
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                    if(lcs[i][j] == lcs[i-1][j])dp[i][j]+=dp[i-1][j];
                    if(lcs[i][j] == lcs[i][j-1])dp[i][j]+=dp[i][j-1];
                    if(lcs[i][j] == lcs[i-1][j-1])dp[i][j]-=dp[i-1][j-1];
                    dp[i][j]%=mod;
                    if(dp[i][j] < 0)dp[i][j]+=mod;
                }
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",a+1,b+1);
        la=strlen(a+1);
        lb=strlen(b+1);
        DP();
        printf("%d %d\n",lcs[la][lb],dp[la][lb]);
    }
    return 0;
}