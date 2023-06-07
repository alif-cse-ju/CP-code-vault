#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

const int M=1e5+5;

int a[M],dp[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=0;i<=a[1];i++)dp[i]=0;
        for(int i=1;i<=n;i++)
        {
            int nxt=a[n]+100;
            for(int j=1;j<=min(a[i],k);j=(a[i]/(a[i]/j))+1)
            {
                int v=a[i]/j;
                dp[v+1]=max(dp[v+1], nxt), nxt=v;
            }
            dp[0]=max(dp[0], nxt);
        }
        int ans=INT_MAX;
        for(int i=0;i<=a[1];i++)
        {
            if(i)dp[i]=max(dp[i], dp[i-1]);
            ans=min(ans, dp[i]-i);
        }
        cout << ans << '\n';
    }
    return 0;
}