#include<bits/stdc++.h>
using namespace std;
const int N=72;
bool visited[N][N][N][N];
int k,m,n,a[N][N],dp[N][N][N][N];
int DP(int i,int j,int nichi,int mod)
    if(i > n)return (mod == 0 ? 0 : INT_MIN);
    int &ans=dp[i][j][nichi][mod];
    if(visited[i][j][nichi][mod])return ans;
    visited[i][j][nichi][mod]=1;
    int di,dj;
    if(j == m)di=i+1,dj=1;
    else di=i,dj=j+1;
    ans=DP(di,dj,(dj == 1 ? 0 : nichi),mod);
    if(nichi < m/2)ans=max(ans,a[i][j]+DP(di,dj,(dj == 1 ? 0 : nichi+1),(mod+a[i][j])%k));
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cin >> a[i][j];
    }
    cout << DP(1,1,0,0);
    return 0;