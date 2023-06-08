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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int bud,leaf;
bool visited[M];
vector<int>adj[M];
void DFS(int x,int p)
    int cnt=0;
    visited[x]=0;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x),cnt+=(1-visited[y]);
    }
    if(cnt)
    {
        visited[x]=1;
        leaf+=cnt,++bud;
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
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        bud=leaf=0;
        DFS(1,0);
        cout << leaf-bud+1 << '\n';
    }
    return 0;
}