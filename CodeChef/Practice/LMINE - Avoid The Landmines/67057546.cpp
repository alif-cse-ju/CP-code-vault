#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M];
ll fact[N];
vector<ll>dp[N];
vector<bool>mark[N];
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
ll nCr(int n,int r)
{
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}
void PreCal()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%mod;
}
void Solve()
{
    int m,n,x,y;cin >> n >> m >> x >> y;
    int height=0,width=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        height=max(height, a[i]/m);
        width=max(width, a[i]%m);
    }
    for(int i=0;i<=height;i++)dp[i].resize(width+1, 0), mark[i].resize(width+1, 0);
    for(int i=0;i<n;i++)mark[a[i]/m][a[i]%m]=1;
    if(mark[0][0])
    {
        cout << "0";
        return;
    }
    if(x <= height  &&  y <= width  &&  mark[x][y])
    {
        cout << "0";
        return;
    }
    ll ans=nCr(x+y,x);
    dp[0][0]=1, height=min(height, x), width=min(width, y);
    for(int i=0;i<=height;i++)
    {
        for(int j=0;j<=width;j++)
        {
            if(i)
            {
                dp[i][j] += dp[i-1][j];
                if(dp[i][j] >= mod)dp[i][j] -= mod;
            }
            if(j)
            {
                dp[i][j] += dp[i][j-1];
                if(dp[i][j] >= mod)dp[i][j] -= mod;
            }
            if(mark[i][j])
            {
                ll tmp=(dp[i][j] * nCr(x-i+y-j, x-i))%mod;
                ans -= tmp, dp[i][j]=0;
                if(ans < 0)ans += mod;
            }
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    Solve();
    return 0;
}