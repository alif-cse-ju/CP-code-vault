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
long long dp[10][N];
void PreCal()
    int i,j;
    for(i=0;i<10;i++)dp[i][0]=1;
    for(i=1;i<N;i++)
    {
        for(j=0;j<9;j++)dp[j][i]=dp[j+1][i-1];
        dp[9][i]=(dp[0][i-1]+dp[1][i-1])%mod;
    }
int main()
    FAST();
    int m,n,t;
    long long ans;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ans=0;
        while(n)
        {
            ans+=dp[n%10][m];
            n/=10;
            ans%=mod;
        }
        cout << ans << '\n';
    }
    return 0;
}