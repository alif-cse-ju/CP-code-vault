#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
ll ans,l[M],r[M];
vector<int>adj[M];
ll DFS(int x)
    ll val=0;
    for(int y : adj[x])val += DFS(y);
    if(val < l[x])++ans, val=r[x];
    return min(val, r[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=2;i<=n;i++)
        {
            int p;cin >> p;
            adj[p].emplace_back(i);
        }
        for(int i=1;i<=n;i++)cin >> l[i] >> r[i];
        ans=0; ll val=DFS(1);
        cout << ans << '\n';
    }
    return 0;
}