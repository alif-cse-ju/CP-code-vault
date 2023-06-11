#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e3+5;
const int mod=1e9+7;
char a[N],b[N];
vector<int>adj[N];
long long dp[N][25];
int l,m,n,x[N],y[N],cnt[N][N];
long long DP(int curPos,int curIt)
{
    if(a[curIt] != b[curPos])return 0;
    long long &ans=dp[curPos][curIt];
    if(ans > -1)return ans;
    if(curIt == l)return ans=1;
    ans=0;
    for(int it : adj[curPos])
    {
        ans+=DP(it,curIt+1);
        ans%=mod;
    }
    return ans;
}
long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,t;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> l;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            for(j=1;j<=l;j++)dp[i][j]=-1;
            for(j=1;j<=n;j++)cnt[i][j]=0;
        }
        cin >> a+1 >> b+1;
        for(i=1;i<=m;i++)cin >> x[i];
        for(i=1;i<=m;i++)cin >> y[i];
        for(i=1;i<=m;i++)
        {
            adj[x[i]].emplace_back(y[i]);
            adj[y[i]].emplace_back(x[i]);
            ++cnt[min(x[i],y[i])][max(x[i],y[i])];
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(a[1] == b[i])
            {
                ans+=DP(i,1);
                ans%=mod;
            }
        }
        sort(a+1,a+l+1);
        if(a[1] == a[l])
        {
            for(i=1;i<=n;i++)
            {
                if(b[i] == a[1])
                {
                    for(j=i+1;j<=n;j++)
                    {
                        if(b[j] == a[1])
                        {
                            ans-=BigMod(cnt[i][j],l-1);
                            if(ans < 0)ans+=mod;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//