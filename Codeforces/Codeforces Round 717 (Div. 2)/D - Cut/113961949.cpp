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
vector<int>prime[M];
int a[M],pos[M],dp[20][M];
void Sieve()
    int i,j;
    pos[2]=M;
    for(i=2;i<M;i+=2)prime[i].emplace_back(2);
    for(i=3;i<M;i+=2)
    {
        if(prime[i].empty())
        {
            pos[i]=M;
            for(j=i;j<M;j+=i)prime[j].emplace_back(i);
        }
    }
int main()
    FAST();
    int i,j,l,n,r,q,ans;
    Sieve();
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    dp[0][n+1]=n+1;
    for(i=n;i;i--)
    {
        dp[0][i]=dp[0][i+1];
        for(int it : prime[a[i]])
        {
            dp[0][i]=min(dp[0][i],pos[it]);
            pos[it]=i;
        }
    }
    for(i=1;i<20;i++)
    {
        for(j=1;j<=n+1;j++)dp[i][j]=dp[i-1][dp[i-1][j]];
    }
    while(q--)
    {
        cin >> l >> r;
        ans=1;
        for(i=19;i>=0;i--)
        {
            if(dp[i][l] <= r)
            {
                ans+=(1 << i);
                l=dp[i][l];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}