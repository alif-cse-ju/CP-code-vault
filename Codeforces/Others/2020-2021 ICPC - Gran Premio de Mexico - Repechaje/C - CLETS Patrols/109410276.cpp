#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int mod=1e9+7;
double a[202][10002],ans[202][2];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,m,n;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)cin >> a[i][j];
    }
    ans[1][0]=1.00;
    for(k=1;k<=m;k++)
    {
        for(i=1;i<=n;i++)ans[i][k & 1]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)ans[j][k & 1]+=(a[i][j] * ans[i][1-(k & 1)]);
        }
    }
    for(i=1;i<=n;i++)cout << fixed << setprecision(5) << ans[i][m & 1] << '\n';
    return 0;