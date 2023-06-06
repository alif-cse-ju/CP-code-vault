#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5;
const int mod=1e9+7;

int m,n,a[N],b[N],dp[N][N];

int DP(int i,int j)
{
    if(i > n)return m-j+1;
    if(j > m)return n-i+1;
    int &ans=dp[i][j];
    if(ans > -1)return ans;
    ans=INT_MAX;
    ans=min(ans,DP(i+1,j)+1);
    ans=min(ans,DP(i,j+1)+1);
    ans=min(ans,DP(i+1,j+1)+2);
    ans=min(ans,DP(i+1,j+1)+(a[i] != b[j]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)cin >> b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)dp[i][j]=-1;
    }
    cout << DP(1,1);
    return 0;
}