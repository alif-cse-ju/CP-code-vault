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
const int mod=1e9+7;
int ans[M],deg[M];
vector<pair<int,int>>adj[M];
void DFS(int x,int p,bool bit)
    for(auto [y,i] : adj[x])
    {
        if(p ^ y)
        {
            if(bit)ans[i]=3;
            else ans[i]=2;
            bit = !bit;
            DFS(y,x,bit);
        }
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)deg[i]=0, adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            ++deg[x], ++deg[y];
            adj[x].emplace_back(y,i);
            adj[y].emplace_back(x,i);
        }
        for(i=1;i<=n  &&  deg[i] < 3;i++);
        if(i <= n)cout << "-1\n";
        else
        {
            DFS(1,0,0);
            for(i=1;i<n;i++)cout << ans[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}