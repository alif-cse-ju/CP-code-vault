    #include<bits/stdc++.h>
         using namespace std;
         #define LL long long
    #define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
         int k,n;
    LL a[1002],b[1002],dp[1002][1002];
         LL DP(int cur,int pos)
    {
        if(pos > k)return 0;
        if(cur > n)return -1e18;
        if(dp[cur][pos] > -1e18-10)return dp[cur][pos];
        return dp[cur][pos]=max(a[cur]*b[pos]+DP(cur+1,pos+1),DP(cur+1,pos));
    }
         int main()
    {
        FAST();
        int i,j;
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=k;i++)cin >> b[i];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=k;j++)dp[i][j]=-1e18-10;
        }
        cout << DP(0,0);
        return 0;
    }