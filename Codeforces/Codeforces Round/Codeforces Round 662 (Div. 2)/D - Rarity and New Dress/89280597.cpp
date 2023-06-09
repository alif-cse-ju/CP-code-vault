#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL dp[2002][2002];
char s[2002][2002];
int main()
    FAST();
    LL ans=0;
    int i,j,m,n;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> s[i]+1;
        for(j=1;j<=m;j++)
        {
            if(i < 3  ||  j == 1  ||  j == m  ||  s[i][j] != s[i-1][j-1]  ||  s[i][j] != s[i-1][j]  ||  s[i][j] != s[i-1][j+1]  ||  s[i][j] != s[i-2][j])dp[i][j]=1;
            else dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j+1]),min(dp[i-1][j],dp[i-2][j]))+1;
            ans+=dp[i][j];
        }
    }
    cout << ans;
    return 0;