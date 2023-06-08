#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
ll const sz = 400;
vector<ll>adj[sz];
ll val[sz], dp[100005], in[sz], mn[sz], lagbe[sz], visi[sz], flag=0;
ll mod = 1e9+7;
ll n;
void dfs(ll u)
    visi[u] = 1;
    lagbe[u] += val[u];
    for(auto v : adj[u])
    {
        if(visi[v])
        {
            flag = 1;
            return;
        }
        lagbe[v] =  lagbe[u];
        dfs(v);
        mn[u] = max(mn[u], mn[v]+1);
    }
    return;
ll rec(int n,ll k)
    dp[0]=1;
    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=k; i++)
        {
            if(lagbe[j] > i)continue;
            dp[i] += dp[i-lagbe[j]];
            if(dp[i] >= mod)dp[i] -= mod;
        }
    }
    return dp[k];
}
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll i,j,k,s,d,r,m;
     cin>>n >>m >> k;
    for(i=1; i<=n; i++) cin>>val[i];
    for(i=1; i<=m; i++)
    {
        ll x,y;
        cin>> x >> y;
        adj[x].pb(y);
        in[y]++;
    }
     for(i=1; i<=n; i++) if(!in[i] && !flag) dfs(i);
    for(i=1; i<=n; i++)
    {
        if(!visi[i]) flag = 1;
        k -= (mn[i] * val[i]);
    }
     if(flag || k<0)
    {
        cout<<"0"<<endl;
        return 0;
    }
     cout << rec(n, k) << endl;
}