#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod=1e9+7;
int d,m;
vector<int>digits;
LL dp[2000][2000][2];
LL DP(int idx,int sum,bool flag)
    if(idx == digits.size())return (sum == 0);
    if(dp[idx][sum][flag] != -1)return dp[idx][sum][flag];
    LL ans=0;
    if(idx & 1)
    {
        if(flag || d <= digits[idx])ans=DP(idx+1,(sum*10+d)%m,d < digits[idx] ? 1 : flag);
    }
    else
    {
        int i,limit;
        if(flag)limit=9;
        else limit=digits[idx];
        for(i=0;i<=limit;i++)
        {
            if(i == d)continue;
            ans+=DP(idx+1,(sum*10+i)%m,i < limit ? 1 : flag);
            ans%=mod;
        }
    }
    return dp[idx][sum][flag]=ans;
LL Solve(string const& s)
    digits.clear();
    for(char c : s)digits.emplace_back(c-'0');
    memset(dp,-1,sizeof(dp));
    return DP(0,0,0);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    LL ans;
    int i,l;
    string a,b;
    cin >> m >> d >> a >> b;
    l=a.size();
    for(i=l-1;i>=0;i--)
    {
        if(a[i] == '0')a[i]='9';
        else
        {
            --a[i];
            break;
        }
    }
    ans=Solve(b)-Solve(a);
    cout << (ans+mod)%mod;
    return 0;
}