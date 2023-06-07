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
int ans[M+M],cnt,n,p;
vector<pair<int,int>>adj[M];
void DFS(int x,int par)
    for(auto [y,i] : adj[x])
    {
        if(par ^ y)
        {
            ++cnt;
            if(ans[x] >= n)ans[y]=cnt, ans[i+n]=cnt+n;
            else ans[y]=cnt+n, ans[i+n]=cnt;
            DFS(y,x);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> p, n=(1 << p);
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y,i);
            adj[y].emplace_back(x,i);
        }
        cnt=0, ans[1]=n, DFS(1,1);
        cout << "1\n";
        for(int i=1;i<=n;i++)cout << ans[i] << ' '; cout << '\n';
        for(int i=n+1;i<n+n;i++)cout << ans[i] << ' '; cout << '\n';
    }
    return 0;
}