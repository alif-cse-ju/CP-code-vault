#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int d,n,dp[N];
int DP(int cur)
    if(cur > n)return N;
    if(cur == n)return 1;
    int &ans=dp[cur];
    if(ans != -1)return ans;
    if(s[cur] == '0')return ans=N;
    ans=INT_MAX;
    for(int i=1;i<=d;i++)ans=min(ans,DP(cur+i)+1);
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> d >> s+1;
    memset(dp,-1,sizeof(dp));
    dp[1]=DP(1);
    if(dp[1] > n)cout << "-1";
    else cout << dp[1]-1;
    return 0;