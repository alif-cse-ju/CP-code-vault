#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
const int mod=1e9+7;

char grid[N][N];
long long dp[N][N],D[N][N],H[N][N],V[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> grid[i]+1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i == 1  &&  j == 1)dp[1][1]=D[1][1]=H[1][1]=V[1][1]=1;
            else if(grid[i][j] == '#')dp[i][j]=D[i][j]=H[i][j]=V[i][j]=0;
            else
            {
                dp[i][j]=(D[i-1][j-1]+H[i][j-1]+V[i-1][j])%mod;
                D[i][j]=(D[i-1][j-1]+dp[i][j])%mod;
                H[i][j]=(H[i][j-1]+dp[i][j])%mod;
                V[i][j]=(V[i-1][j]+dp[i][j])%mod;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
