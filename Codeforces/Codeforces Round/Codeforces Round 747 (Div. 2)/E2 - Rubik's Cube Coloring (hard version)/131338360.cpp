#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
map<ll,ll>dp[7];
map<ll,map<ll,int>>colored;
int Check(string& s)
    if(s[0] == 'r')return 1;
    if(s[0] == 'o')return 2;
    if(s[0] == 'b')return 3;
    if(s[0] == 'g')return 4;
    if(s[0] == 'w')return 5;
    return 6;
bool Ok(int& x,int& y)
    if(x == y)return 0;
    if(!x  ||  !y)return 1;
    if(x & 1)return y != x+1;
    return y != x-1;
ll BigMod(ll val,ll pow)
    ll res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
 ll DP(ll cur,int lvl,int pColor)
{
    int cnt=0;
    for(int i=1;i<7;i++)cnt += Ok(pColor,i);
    if(lvl == 1)
    {
        if(colored[cur].find(cur) == colored[cur].end())return cnt;
        return Ok(pColor,colored[cur][cur]);
    }
    if(colored[cur].empty())
    {
        ll child=(1ll << lvl)-2;
        return (1ll * cnt * BigMod(4,child))%mod;
    }
    if(dp[pColor].find(cur) != dp[pColor].end())return dp[pColor][cur];
    ll left=cur << 1ll;
    ll right=left+1,ans=0;
    int clr=colored[cur][cur];
    for(int i=1;i<7;i++)
    {
        if(clr  &&  clr != i)continue;
        if(Ok(i,pColor)  &&  Ok(i,colored[cur][left])  &&  Ok(i,colored[cur][right]))
        {
            ans += DP(left,lvl-1,i) * DP(right,lvl-1,i);
            ans %= mod;
        }
    }
    return dp[pColor][cur]=ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y;
    string s;
    int n,lvl,clr;
    cin >> lvl >> n;
    while(n--)
    {
        cin >> x >> s;
        clr=Check(s),y=x;
        while(x)colored[x][y]=clr, x >>= 1ll;
    }
    cout << DP(1,lvl,0);
    return 0;
}