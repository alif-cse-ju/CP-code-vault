#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+5;
int a[M];
ll dp[M][2];
vector<int>adj[M];
ll DFS(int x,int p,int player)
{
    ll &ans=dp[x][player];
    if(ans > -1e15)return ans;
    ans=a[x];
    vector<ll>v;
    for(int y : adj[x])
    {
        if(p ^ y)v.emplace_back(DFS(y,x,!player));
    }
    if(player)
    {
        sort(v.begin(),v.end());
        if(!v.empty())ans += v.back();
    }
    else
    {
        sort(v.begin(),v.end());
        if(!v.empty())ans += v[0];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            adj[i].clear();
            dp[i][0]=dp[i][1]=-1e15;
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        cout << DFS(1,0,0) << '\n';
    }
    return 0;
}