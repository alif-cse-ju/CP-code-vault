#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int k;
ll dp[M][2];
vector<pair<int,int>>adj[M];
void DFS(int x,int p)
    ll ans=0;
    vector<ll>tmp;
    for(auto& [y,z] : adj[x])
    {
        if(p ^ y)
        {
            DFS(y,x);
            ans+=dp[y][0];
            tmp.emplace_back(dp[y][1]+z-dp[y][0]);
        }
    }
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    for(int i=0;i<min(k,(int)tmp.size());i++)ans+=max(0ll,tmp[i]);
    dp[x][0]=dp[x][1]=ans;
    if(k <= (int)tmp.size())dp[x][1]-=max(0ll,tmp[k-1]);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y >> z;
            adj[x].emplace_back(y,z);
            adj[y].emplace_back(x,z);
        }
        DFS(1,0);
        cout << dp[1][0] << '\n';
    }
    return 0;
}