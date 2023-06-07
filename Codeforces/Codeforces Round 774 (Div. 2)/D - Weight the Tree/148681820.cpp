#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+5;
ll dpVal[M][2];
vector<int>adj[M];
int dp[M][2],val[M];
int DP(int x,int p,bool good)
    int &ans=dp[x][good];
    if(ans > -1)return ans;
    if(good)ans=1;
    else ans=0;
    if(good)dpVal[x][1]=(int)adj[x].size();
    else dpVal[x][0]=1;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            if(good)ans += DP(y, x, 0), dpVal[x][1] += dpVal[y][0];
            else
            {
                ans += max(DP(y, x, 1), DP(y, x, 0));
                if(dp[y][1] > dp[y][0])dpVal[x][0] += dpVal[y][1];
                else if(dp[y][1] < dp[y][0])dpVal[x][0] += dpVal[y][0];
                else dpVal[x][0] += min(dpVal[y][0], dpVal[y][1]);
            }
        }
    }
    return ans;
void Dhon(int x,int p,bool good)
{
    if(good)val[x]=(int)adj[x].size();
    else val[x]=1;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            if(good)Dhon(y,x,0);
            else
            {
                if(dp[y][1] > dp[y][0])Dhon(y,x,1);
                else if(dp[y][1] < dp[y][0])Dhon(y,x,0);
                else
                {
                    if(dpVal[y][1] <= dpVal[y][0])Dhon(y,x,1);
                    else Dhon(y,x,0);
                }
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum=0;
    int ans,i,n,x,y;
    cin >> n;
    for(i=1; i<n; i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    if(n == 2)
    {
        cout << "2 2\n1 1";
        return 0;
    }
    for(i=1; i<=n; i++)
    {
        dp[i][0]=dp[i][1]=-1;
        dpVal[i][0]=dpVal[i][1]=LLONG_MAX;
    }
    ans=max(DP(1,0,0), DP(1,0,1));
    if(dp[1][1] > dp[1][0])Dhon(1,0,1);
    else if(dp[1][1] < dp[1][0])Dhon(1,0,0);
    else
    {
        if(dpVal[1][1] <= dpVal[1][0])Dhon(1,0,1);
        else Dhon(1,0,0);
    }
    for(i=1; i<=n; i++)sum += val[i];
    cout << ans << ' ' << sum << '\n';
    for(i=1; i<=n; i++)cout << val[i] << ' ';
    return 0;
}