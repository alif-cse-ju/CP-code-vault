#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int ii,xx;
map<int,bool>visited;
map<int,vector<pair<int,int>>>adj;
void DFS(int x,int p)
    visited[x]=1;
    for(auto [y,i] : adj[x])
    {
        if(y ^ p)
        {
            if(visited.find(y) == visited.end())DFS(y,x);
            else ii=i,xx=y;
        }
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n;
        adj.clear();
        for(i=1; i<=n; i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y,i);
            adj[y].emplace_back(x,i);
        }
        z=x;
        visited.clear();
        vector<tuple<int,int,int>>ans;
        DFS(z,z);
        for(auto [x,v] : adj)
        {
            if(visited.find(x) == visited.end())
            {
                if((int)v.size() == 1)
                {
                    DFS(x,x);
                    auto [y,i]=v[0];
                    ans.emplace_back(make_tuple(i,x,z));
                }
            }
        }
        for(auto [x,v] : adj)
        {
            if(visited.find(x) == visited.end())
            {
                DFS(x,x);
                ans.emplace_back(make_tuple(ii,xx,z));
            }
        }
        cout << (int)ans.size() << '\n';
        for(auto [i,x,y] : ans)cout << i << ' ' << x << ' ' << y << '\n';
    }
    return 0;
}