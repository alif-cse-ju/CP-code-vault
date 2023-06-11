#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long dp[62][2];
vector<int>digitsK,digitsN;
long long DP(int curPos,bool smaller)
{
    if(curPos == 61)return 1;
    long long &ans=dp[curPos][smaller];
    if(ans > -1)return ans;
    ans=0;
    if(smaller)
    {
        ans+=DP(curPos+1,1);
        if(!digitsK[curPos])ans+=DP(curPos+1,1);
    }
    else
    {
        ans+=DP(curPos+1,digitsN[curPos]);
        if(!digitsK[curPos]  &&  digitsN[curPos])ans+=DP(curPos+1,0);
    }
    return ans;
}
long long Check(const long long& n)
{
    digitsN.clear();
    for(int i=60;i>=0;i--)digitsN.emplace_back((n >> i) & 1ll);
    memset(dp,-1,sizeof(dp));
    return DP(0,0);
}
int main()
{
    FAST();
    int t;
    long long i,k,l,m,n,r,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> k >> x;
        digitsK.clear();
        for(i=60;i>=0;i--)digitsK.emplace_back((k >> i) & 1ll);
        l=ans=0,r=1e18;
        while(l <= r)
        {
            m=(l+r) >> 1ll;
            if(m-Check(m)+1 <= x)ans=m,l=m+1;
            else r=m-1;
        }
        cout << ans << '\n';
    }
    return 0;
}