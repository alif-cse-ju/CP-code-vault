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
vector<int>adj[M];
int l,timer,lvl[M],inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
    up[cur][0]=par;
    lvl[cur]=lvl[par]+1;
    inTime[cur]=++timer;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
    }
    outTime[cur]=++timer;
bool IsAncestor(int x,int y)
    return inTime[x] <= inTime[y]  &&  outTime[x] >= outTime[y];
}
 int LCA(int x,int y)
{
    if(IsAncestor(x,y))return x;
    if(IsAncestor(y,x))return y;
    for(int i=l;i>=0;i--)
    {
        if(!IsAncestor(up[x][i],y))x=up[x][i];
    }
    return up[x][0];
}
 void PreProcess(const int& numberOfNodes)
{
    l=ceil(log2(numberOfNodes));
    DFS(1,1);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,i,k,n,q,x,y,z;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    lvl[1]=-1;
    PreProcess(n);
    cin >> q;
    while(q--)
    {
        cin >> x >> y >> a >> b >> k;
        int ab=LCA(a,b),xy=LCA(x,y);
        int ax=LCA(a,x),ay=LCA(a,y);
        int bx=LCA(b,x),by=LCA(b,y);
        int loop=lvl[x]+lvl[y]-2*lvl[xy]+1;
         z=lvl[a]+lvl[b]-2*lvl[ab];//going from a - b
        if(z <= k  &&  (k-z)%2 == 0)
        {
            cout << "YES\n";
            continue;
        }
         z=lvl[a]+lvl[x]-2*lvl[ax]+lvl[b]+lvl[x]-2*lvl[bx];//going from a - x - b
        if(z <= k  &&  ((k-z)%loop == 0  ||  (k-z)%2 == 0))
        {
            cout << "YES\n";
            continue;
        }
         z=lvl[a]+lvl[y]-2*lvl[ay]+lvl[b]+lvl[y]-2*lvl[by];//going from a - y - b
        if(z <= k  &&  ((k-z)%loop == 0  ||  (k-z)%2 == 0))
        {
            cout << "YES\n";
            continue;
        }
         z=lvl[a]+lvl[x]-2*lvl[ax]+lvl[b]+lvl[y]-2*lvl[by];//going from a - x - y - b
        if(z <= k  &&  ((k-z)%loop == 1  ||  (k-z)%2 == 1))
        {
            cout << "YES\n";
            continue;
        }
         z=lvl[a]+lvl[y]-2*lvl[ay]+lvl[b]+lvl[x]-2*lvl[bx];//going from a - y - x - b
        if(z <= k  &&  ((k-z)%loop == 1  ||  (k-z)%2 == 1))
        {
            cout << "YES\n";
            continue;
        }
         cout << "NO\n";
    }
    return 0;
}