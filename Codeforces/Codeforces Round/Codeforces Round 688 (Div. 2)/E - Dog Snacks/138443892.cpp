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
int ans;
vector<int>adj[M];
int DFS(int x,int p)
    if((int)adj[x].size() == 1  &&  x != 1)return 1;
    vector<int>v;
    for(int y : adj[x])
    {
        if(p ^ y)v.emplace_back(DFS(y,x));
    }
    sort(v.begin(),v.end());
    if((int)v.size() > 1)
    {
        if(x == 1)ans=max(ans,v.back()), v.pop_back();
        ans=max(ans,v.back()+1);
    }
    ans=max(ans,v[0]);
    return v[0]+1;
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
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        ans=0, DFS(1,0);
        cout << ans << '\n';
    }
    return 0;
}