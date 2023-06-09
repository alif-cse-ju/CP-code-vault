#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;
char a[N],b[5];
int n,dp[N][N][N];
int DP(int idx,int rem,int cur)
    if(idx > n)return 0;
    if(dp[idx][rem][cur] > -1)return dp[idx][rem][cur];
    int ans;
    if(a[idx] == b[1])
    {
        ans=DP(idx+1,rem,cur+1);
        if(rem)ans=max(ans,cur+DP(idx+1,rem-1,cur));
    }
    else if(a[idx] == b[2])
    {
        ans=cur+DP(idx+1,rem,cur);
        if(rem)ans=max(ans,DP(idx+1,rem-1,cur+1));
    }
    else
    {
        ans=DP(idx+1,rem,cur);
        if(rem)ans=max(ans,DP(idx+1,rem-1,cur+1));
        if(rem)ans=max(ans,cur+DP(idx+1,rem-1,cur));
    }
    return dp[idx][rem][cur]=ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,m,ans=0;
    cin >> n >> m >> a+1 >> b+1;
    if(b[1] == b[2])
    {
        for(i=1;i<=n;i++)ans+=(a[i] == b[1]);
        ans=min(ans+m,n);
        cout << (ans*(ans-1))/2;
        return 0;
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=n;k++)dp[i][j][k]=-1;
        }
    }
    cout << DP(1,m,0);
    return 0;
}