#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
const int n = 4e4+1;
const int sz = 16384;
string s[n];
vector<int>adj[n];
int a[n],ans[n],b[n],dp[16][sz],par[n],_size[n];
void DFS(int x)
    _size[x]=1;
    for(int &y : adj[x])DFS(y), _size[x]+=_size[y];
void DFS2(int x,int xr,int lightCnt)
    ans[x]=dp[lightCnt][xr];
    int mx=-1,heavyChild=0;
    for(int &y : adj[x])
    {
        if(_size[y] > mx)mx=_size[y], heavyChild=y;
    }
    for(int &y : adj[x])
    {
        if(heavyChild ^ y)
        {
            for(int i=0;i<sz;i++)dp[lightCnt+1][i]=min(dp[lightCnt][i], dp[lightCnt][i^a[y]]+b[y]);
            DFS2(y,(a[y]^xr),lightCnt+1);
        }
    }
    if(!heavyChild)return;
    for(int i=0;i<sz;i++)dp[lightCnt+1][i]=min(dp[lightCnt][i], dp[lightCnt][i^a[heavyChild]]+b[heavyChild]);
    for(int i=0;i<sz;i++)dp[lightCnt][i]=dp[lightCnt+1][i];
    DFS2(heavyChild,(a[heavyChild]^xr),lightCnt);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;cin >> q;
    int x=0;
    for(int i=1;i<=q;i++)
    {
        cin >> s[i];
        if(s[i] == "ADD")
        {
            cin >> a[i] >> b[i];
            adj[x].emplace_back(i), par[i]=x, x=i;
        }
        else x=par[x];
    }
    DFS(0);
    for(int i=1;i<sz;i++)dp[0][i]=2e9;
    DFS2(0,0,0), x=0;
    for(int i=1;i<=q;i++)
    {
        if(s[i] == "ADD")x=i;
        else x=par[x];
        cout << ans[x] << '\n';
    }
    return 0;
}