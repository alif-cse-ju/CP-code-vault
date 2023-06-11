#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int cnt1[N];
long long val[N];
long long cnt2[N];
vector<int>adj[N];
void DFS1(int x,int par)
{
    cnt1[x]=cnt2[x]=1;
    vector<long long>v;
    for(int y : adj[x])
    {
        if(y ^ par)
        {
            DFS1(y,x);
            cnt1[x]+=cnt1[y];
            v.emplace_back(cnt2[y]);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    long long temp=0;
    for(auto it : v)cnt2[x]+=(++temp)*it;
}
void DFS2(int x,int par)
{
    vector<pair<pair<long long,int>,int>>v;
    for(int y : adj[x])
    {
        if(y ^ par)v.push_back({{cnt2[y],cnt1[y]},y});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    long long temp=0;
    for(auto it : v)
    {
        val[it.second]=(val[x]*(++temp))%mod;
        DFS2(it.second,x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> val[1];
        for(i=1; i<=n; i++)adj[i].clear();
        for(i=1; i<n; i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS1(1,0);
        DFS2(1,0);
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans+=val[i];
            ans%=mod;
        }
        cout << ans << '\n';
    }
    return 0;
}