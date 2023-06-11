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
const int mod=1e9+7;
const int sz = 1e3+5;
int dist[sz];
vector<int>adj[sz];
void Ask(vector<int>&v)
{
    cout << "? " << (int)v.size();
    while(!v.empty())cout << ' ' << v.back(), v.pop_back();
    cout << endl;
}
void DFS(int x,int p)
{
    dist[x]=dist[p]+1;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y, x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>v,vv;
    int i,l,lvl,m,n,r,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1,0);
        l=1, r=n, v.clear();
        while(l <= r)
        {
            m=(l+r) >> 1;
            for(i=1;i<=n;i++)
            {
                if(dist[i] <= m)v.emplace_back(i);
            }
            Ask(v);
            cin >> x;
            if(x)r=m-1;
            else l=m+1;
        }
        lvl=r+1;
        for(i=1;i<=n;i++)
        {
            if(dist[i] == lvl)v.emplace_back(i);
        }
        l=1, r=(int)v.size();
        while(l <= r)
        {
            m=(l+r) >> 1;
            for(i=0;i<m;i++)vv.emplace_back(v[i]);
            Ask(vv);
            cin >> x;
            if(x)r=m-1;
            else l=m+1;
        }
        cout << "! " << v[r] << endl;
    }
    return 0;
}