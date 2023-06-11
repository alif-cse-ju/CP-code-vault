#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],dp[N][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            dp[i][0]=0,dp[i][1]=-1;
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            dp[a[i]][0]=max(dp[a[i]][0],dp[a[i]][1]+1);
            dp[a[i]][1]=max(dp[a[i]][1],ans+1);
            ans=max(ans,dp[a[i]][0]);
        }
        cout << n-ans << '\n';
    }
    return 0;
}
//1060,1422