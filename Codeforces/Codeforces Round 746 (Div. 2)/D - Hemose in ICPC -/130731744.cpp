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
const int M=1e3+5;
const int N=1e6+5;
const int mod=1e9+9;
vector<int>adj[M];
int T,a[M],par[M];
void DFS(int x,int p)
    a[++T]=x, par[x]=p;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,mx,m,n,r,x,y;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    cout << "? " << n;
    for(i=1;i<=n;i++)cout << ' ' << i;
    cout << endl;
    cin >> mx;
    l=2,r=n;
    while(l < r)
    {
        m=(l+r) >> 1;
        cout << "? " << m;
        for(i=1;i<=m;i++)cout << ' ' << a[i];
        cout << endl;
        cin >> x;
        if(x == mx)r=m;
        else l=m+1;
    }
    y=a[r], x=par[y];
    cout << "! " << x << ' ' << y << endl;
    return 0;
}