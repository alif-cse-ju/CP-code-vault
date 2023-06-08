#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=4e5+5;
const int mod=1e9+7;
int pos[N];
bool visited[N];
vector<int>adj[N];
ll BigMod(ll val,ll pow)
    ll res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
void DFS(int x)
{
    if(visited[x])return;
    visited[x]=1;
    for(int y : adj[x])DFS(y);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
            adj[i].clear();
        }
        for(i=1;i<=n;i++)cin >> x,pos[x]=i;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            adj[i].emplace_back(pos[x]);
            adj[pos[x]].emplace_back(i);
        }
        cnt=0;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                ++cnt;
                DFS(i);
            }
        }
        cout << BigMod(2,cnt) << '\n';
    }
    return 0;
}