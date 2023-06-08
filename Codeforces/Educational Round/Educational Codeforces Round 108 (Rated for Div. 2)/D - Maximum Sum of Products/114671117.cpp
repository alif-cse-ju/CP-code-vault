#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e3+1;
const int N=2e5+5;
const int mod=1e9+7;
long long a[M],b[M],pre[M],dp[M][M];
long long DP(int i,int j)
    if(i > j)return 0;
    if(i == j)return a[i]*b[i];
    long long &ans=dp[i][j];
    if(ans > -1)return ans;
    return ans=a[i]*b[j]+a[j]*b[i]+DP(i+1,j-1);
int main()
    FAST();
    int i,j,n;
    long long ans;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        for(j=i+1;j<=n;j++)dp[i][j]=-1;
    }
    for(i=1;i<=n;i++)
    {
        cin >> b[i];
        pre[i]=pre[i-1]+a[i]*b[i];
    }
    ans=pre[n];
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)ans=max(ans,pre[i-1]+pre[n]-pre[j]+DP(i,j));
    }
    cout << ans;
    return 0;
}