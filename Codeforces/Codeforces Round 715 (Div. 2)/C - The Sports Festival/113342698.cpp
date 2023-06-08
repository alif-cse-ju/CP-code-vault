#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e3+5;
const int mod=1e9+7;
int a[N];
long long dp[N][N];
long long DP(int l,int r)
    if(dp[l][r] > -1)return dp[l][r];
    if(l == r)return dp[l][r]=0;
    return dp[l][r]=a[r]-a[l]+min(DP(l+1,r),DP(l,r-1));
int main()
    FAST();
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    memset(dp,-1,sizeof(dp));
    cout << DP(1,n);
    return 0;