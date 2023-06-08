#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
bool ok;
int a[M],xr,_xr[M];
vector<int>adj[M],tmp;
void DFS(int x,int p)
    _xr[x]=a[x];
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS(y,x);
            _xr[x] ^= _xr[y];
        }
    }
 void DFS1(int x,int p)
{
    for(int y : adj[x])
    {
        if(p ^ y)DFS1(y,x);
    }
    if(_xr[x] == (xr ^ _xr[x]))ok=1;
}
 int DFS2(int x,int p)
{
    int xrX=a[x];
    for(int y : adj[x])
    {
        if(p ^ y)xrX ^= DFS2(y,x);
    }
    if(xrX == xr)
    {
        tmp.emplace_back(x);
        return 0;
    }
    return xrX;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,k,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        xr = 0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            xr ^= a[i];
            adj[i].clear();
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        ok=0;
        DFS(1,0);
        if(!xr)DFS1(1,0);
        if(!ok  &&  k > 2)
        {
            tmp.clear();
            x=DFS2(1,0);
            if(!x  &&  (int)tmp.size() > 1)ok=1;
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}