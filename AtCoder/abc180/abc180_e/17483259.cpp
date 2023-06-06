#include<bits/stdc++.h>

using namespace std;

long long x[17],y[17],z[17],dp[1<< 17][17],dist[17][17];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n;
    cin >> n;
    for(i=0;i<n;i++)cin >> x[i] >> y[i] >> z[i];
    for(i=0;i<(1 << n);i++)
    {
        for(j=0;j<n;j++)dp[i][j]=INT_MAX;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)dist[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j])+max(0LL,z[j]-z[i]);
    }
    dp[0][0]=0;
    for(i=1;i<(1 << n);i++)
    {
        for(j=0;j<n;j++)
        {
            if((i >> j) & 1)
            {
                for(k=0;k<n;k++)dp[i][j]=min(dp[i][j],dp[i-(1 << j)][k]+dist[k][j]);
            }
        }
    }
    cout << dp[(1 << n)-1][0];
    return 0;
}
