#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e3+5;
const int N=2e5+5;
const int mod=1e9+7;
int n;
long long dp[M][M][2];
long long DP(int cur,int k,bool dir)
    if(!cur  ||  cur > n  ||  k == 1)return 1;
    long long &ans=dp[cur][k][dir];
    if(ans > -1)return ans;
    ans=0;
    if(dir)
    {
        if(cur <= n)ans+=DP(cur+1,k,1);
        if(cur)ans+=DP(cur-1,k-1,0);
    }
    else
    {
        if(cur)ans+=DP(cur-1,k,0);
        if(cur <= n)ans+=DP(cur+1,k-1,1);
    }
    return ans%=mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=0;i<=n;i++)
        {
            for(j=1;j<=k;j++)dp[i][j][0]=dp[i][j][1]=-1;
        }
        cout << DP(1,k,1) << '\n';
    }
    return 0;
}
//