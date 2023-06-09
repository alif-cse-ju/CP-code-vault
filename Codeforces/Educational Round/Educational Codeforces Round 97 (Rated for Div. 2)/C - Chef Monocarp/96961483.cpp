#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N],dp[N][(N << 1)];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=n+n;j++)
            {
                if(j < i)dp[i][j]=1e8;
                else dp[i][j]=min(dp[i][j-1] , dp[i-1][j-1]+abs(a[i]-j));
            }
        }
        cout << dp[n][n+n] << '\n';
    }
    return 0;