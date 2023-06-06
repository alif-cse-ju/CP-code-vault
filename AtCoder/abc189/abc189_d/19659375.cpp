#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5;
const int mod=1e9+7;

int n;
string s[N];
long long dp[65][2];

long long DP(int idx,int val)
{
    if(idx > n)return val;
    long long &ans=dp[idx][val];
    if(ans > -1)return ans;
    if(s[idx] == "AND")
    {
        ans=DP(idx+1,0);
        ans+=DP(idx+1,val);
    }
    else
    {
        ans=DP(idx+1,val);
        ans+=DP(idx+1,1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i;
    cin >> n;
    for(i=1;i<=n;i++)cin >> s[i];
    memset(dp,-1,sizeof(dp));
    cout << DP(1,0)+DP(1,1);
    return 0;
}