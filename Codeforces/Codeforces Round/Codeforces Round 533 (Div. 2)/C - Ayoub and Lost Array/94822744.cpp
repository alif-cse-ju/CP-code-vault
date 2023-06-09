#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const long long mod=1e9+7;
long long cnt[4],dp[N][4];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,l,n,r;
    cin >> n >> l >> r;
    --l;
    cnt[0]=r/3-l/3;
    cnt[1]=(r+2)/3-(l+2)/3;
    cnt[2]=(r+1)/3-(l+1)/3;
    dp[0][0]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                dp[i+1][(j+k)%3]+=dp[i][j]*cnt[k];
                dp[i+1][(j+k)%3]%=mod;
            }
        }
    }
    cout << dp[n][0];
    return 0;