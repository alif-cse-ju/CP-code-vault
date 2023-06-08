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
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
vector<int>adj[M];
vector<pair<int,int>>_tree[N];
int a[M],ans[M],lvl[M],primeDiv[N];
void Sieve()
    int i,j;
    for(i=2;i<N;i+=2)primeDiv[i]=2;
    for(i=3;i<N;i+=2)
    {
        if(!primeDiv[i])
        {
            for(j=i;j<N;j+=2*i)
            {
                if(!primeDiv[j])primeDiv[j]=i;
            }
        }
    }
}
 void Insert(int i)
{
    int x=a[i],y;
    pair<int,int>p={-1,-1};
    while(x > 1)
    {
        y=primeDiv[x];
        while(x%y == 0)x/=y;
        if(!_tree[y].empty())p=max(p, _tree[y].back());
        _tree[y].emplace_back(lvl[i],i);
    }
    ans[i]=p.second;
}
 void Erase(int i)
{
    int x=a[i],y;
    while(x > 1)
    {
        y=primeDiv[x];
        while(x%y == 0)x/=y;
        _tree[y].pop_back();
    }
}
 void DFS(int x,int p)
{
    lvl[x]=lvl[p]+1;
    Insert(x);
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    Erase(x);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,q,x,y;
    Sieve();
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    while(q--)
    {
        cin >> t;
        if(t == 1)cin >> x, cout << ans[x] << '\n';
        else
        {
            cin >> i >> x;
            a[i]=x, DFS(1,0);
        }
    }
    return 0;
}