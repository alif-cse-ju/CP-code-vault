#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
//K-th parent
vector<int>adj[M];
int LG,dist[N],dp[M][20];
void DFS(int cur,int par)
{
    dist[cur]=dist[par]+1;
    dp[cur][0]=par;
    for(int i=1;i<=LG;i++)dp[cur][i]=dp[dp[cur][i-1]][i-1];
    for(int x : adj[cur])DFS(x,cur);
}
void PreCal(const int &n)
{
    LG=ceil(log2(n));
    dist[n]=-1;
    DFS(n,n);
}
int FindKth(int node,int k)
{
    for(int i=LG;i>=0;i--)
    {
        if((1 << i) <= k)
        {
            k-=(1 << i);
            node=dp[node][i];
        }
    }
    return node;
}
//K-th parent
ll a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll s;
    int ans,i,k,l,m,n,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        adj[n+1].clear();
        for(i=1;i<=n;i++)cin >> a[i],adj[i].clear();
        for(i=2;i<=n;i++)a[i]+=a[i-1];
        for(i=1;i<=n;i++)
        {
            l=i,r=n;
            while(l <= r)
            {
                m=(l+r) >> 1;
                if(a[m]-a[i-1] <= s)l=m+1;
                else r=m-1;
            }
            adj[l].emplace_back(i);
        }
        ans=0;
        PreCal(n+1);
        for(i=1;i<=n;i++)
        {
            if(dist[i] < k)l=n+1;
            else l=FindKth(i,k);
            ans=max(ans,l-i);
        }
        cout << ans << '\n';
    }
    return 0;
}