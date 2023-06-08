#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int k,m,n;
long long dp[M][M][21];
map<pair<pair<int,int>,pair<int,int>>,int>mp;
int main()
    FAST();
    int i,j,kk,x,y;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<m;j++)
        {
            cin >> x;
            mp[{{i,j},{i,j+1}}]=mp[{{i,j+1},{i,j}}]=x;
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin >> x;
            mp[{{i,j},{i+1,j}}]=mp[{{i+1,j},{i,j}}]=x;
        }
    }
    if(k & 1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cout << "-1 ";
            cout << '\n';
        }
        return 0;
    }
    for(kk=2;kk<=k;kk+=2)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                dp[i][j][kk]=LLONG_MAX;
                for(int it=0;it<4;it++)
                {
                    x=i+dx[it],y=j+dy[it];
                    if(x  &&  y  &&  x <= n  &&  y <= m)dp[i][j][kk]=min(dp[i][j][kk],dp[x][y][kk-2]+2*mp[{{i,j},{x,y}}]);
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cout << dp[i][j][k] << ' ';
        cout << '\n';
    }
    return 0;
}