#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
int a[N],dp[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,ans=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        dp[i]=1;
        if(a[i] > a[i-1])dp[i]+=dp[i-1];
    }
    for(i=1;i<=n;i++)ans=max(ans,dp[i]);
    cout << ans;
    return 0;
}