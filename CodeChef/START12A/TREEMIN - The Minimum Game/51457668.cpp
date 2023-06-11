#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[M];
ll dp[M][2];
vector<int>adj[M];
ll DFS(int x,int p,int player)
{
    ll &ans=dp[x][player];
    ans=a[x];
    vector<ll>v;
    for(int y : adj[x])
    {
        if(p ^ y)v.emplace_back(DFS(y,x,!player));
    }
    sort(v.begin(),v.end());
    if(player && !v.empty())ans += v.back();
    else if(!v.empty())ans += v[0];
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