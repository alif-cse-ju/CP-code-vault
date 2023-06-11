#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,j,k,l,n,t,x,dp[105][105];
    cin >> t;
    while(t--)
    {
        cin >> n >> l;
        for(i=0;i<=l;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i < 2  ||  j == 1)dp[i][j]=i;
                else dp[i][j]=INT_MAX;
            }
        }
        for(i=2;i<=l;i++)
        {
            for(j=2;j<=n;j++)
            {
                for(k=1;k<=i;k++)
                {
                    x=max(dp[k-1][j-1],dp[i-k][j])+1;
                    dp[i][j]=min(dp[i][j],x);
                }
            }
        }
        cout << dp[l][n] << '\n';
    }
    return 0;
}