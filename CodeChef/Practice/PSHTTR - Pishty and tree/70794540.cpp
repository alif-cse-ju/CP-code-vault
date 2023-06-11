#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
ordered_set<int>ost;
int ans[M],dist,_xor[M];
vector<pair<int,int>>adj[M],queries[M];
void Update(int i,int v)
{
    while(i <= dist)_xor[i]=(_xor[i]^v), i+=(i & -i);
}
int Query(int i)
{
    int ans=0;
    while(i)ans=(ans^_xor[i]), i-=(i & -i);
    return ans;
}
void DFS(int x,int p)
{
    for(pair<int,int>&it : queries[x])ans[it.first]=(ans[it.first]^Query(ost.order_of_key(it.second)+1));
    for(pair<int,int>&it : adj[x])
    {
        if(p ^ it.first)
        {
            Update(ost.order_of_key(it.second)+1,it.second);
            DFS(it.first,x);
            Update(ost.order_of_key(it.second)+1,it.second);
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
        int n;cin >> n;
        for(int i=1;i<=n;i++)adj[i].clear(), queries[i].clear();
        ost.clear();
        for(int i=1;i<n;i++)
        {
            int x,y,z;cin >> x >> y >> z;
            ost.insert(z);
            adj[x].emplace_back(y,z);
            adj[y].emplace_back(x,z);
        }
        int q;cin >> q;
        for(int i=1;i<=q;i++)
        {
            int x,y,z;cin >> x >> y >> z;
            ans[i]=0, ost.insert(z);
            queries[x].emplace_back(i,z);
            queries[y].emplace_back(i,z);
        }
        dist=(int)ost.size();
        for(int i=1;i<=dist;i++)_xor[i]=0;
        DFS(1,0);
        for(int i=1;i<=q;i++)cout << ans[i] << '\n';
    }
    return 0;
}