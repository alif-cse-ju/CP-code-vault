#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e3+5;
const int N=2e5+5;
const int mod=1e9+7;
char a[M],b[M];
int la,lb,dp[M][M];
int LCS(int i,int j)
{
    if(i > la  ||  j > lb)return 0;
    int &ans=dp[i][j];
    if(ans >= 0)return ans;
    if(a[i] == b[j])ans=LCS(i+1,j+1)+1;
    else ans=max(LCS(i,j+1),LCS(i+1,j));
    return ans;
}
int main()
{
    FAST();
    cin >> a+1 >> b+1;
    la=strlen(a+1);
    lb=strlen(b+1);
    memset(dp,-1,sizeof(dp));
    cout << LCS(1,1);
    return 0;
}