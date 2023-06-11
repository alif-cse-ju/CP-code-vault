#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
int cnt1[N];
long long val[N];
__int128 cnt2[N];
vector<int>adj[N];
void DFS1(int x,int par)
{
    cnt1[x]=cnt2[x]=1;
    vector<__int128>v;
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
    __int128 temp=0;
    for(auto it : v)cnt2[x]+=(++temp)*it;
}
void DFS2(int x,int par)
{
    vector<pair<pair<__int128,int>,int>>v;
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
//