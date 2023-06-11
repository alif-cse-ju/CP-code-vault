#include<bits/stdc++.h>
using namespace std;
const int N=102;
int colSum[N],dp[N][N];
int DP(int i,int k)
{
    if(i == k)return 0;
    int &ans=dp[i][k],x;
    if(ans > -1)return ans;
    ans=INT_MAX;
    for(int j=i;j<k;j++)
    {
        x=DP(i,j)+DP(j+1,k)+((colSum[j]-colSum[i-1])%100)*((colSum[k]-colSum[j])%100);
        ans=min(ans,x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,x;
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            colSum[i]=colSum[i-1]+x;
            for(j=1;j<=n;j++)dp[i][j]=-1;
        }
        printf("%d\n",DP(1,n));
    }
    return 0;
}