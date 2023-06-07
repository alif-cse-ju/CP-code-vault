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
const int N=1e6+5;
const int mod=998244353;
vector<int>adj[M];
pair<int,int>edges[M];
int n,timer,dist[M],par[M],tag[M],in[M],out[M],sum[2*M];
void DFS(int x,int p,int t,int d)
    in[x] = ++timer;
    dist[x]=d, par[x]=p, tag[x]=t;
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            if(t)DFS(y,x,t,d+1);
            else DFS(y,x,y,d+1);
        }
    }
    out[x] = ++timer;
}
 void Update(int i,int v)
{
    while(i <= (n << 1))sum[i] += v, i += (i & -i);
}
 int Query(int i)
{
    int ans=0;
    while(i)ans += sum[i], i -= (i & -i);
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,mx=0,q,root,t,x,y;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        edges[i]={x,y};
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if((int)adj[i].size() > mx)root=i, mx=(int)adj[i].size();
    }
    DFS(root,0,0,0);
    for(i=1;i<=n;i++)Update(in[i],1), Update(out[i],-1);
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> i;
            x=edges[i].first, y=edges[i].second;
            if(x == par[y])Update(in[y],2), Update(out[y],-2);
            else Update(in[x],2), Update(out[x],-2);
        }
        else if(t == 2)
        {
            cin >> i;
            x=edges[i].first, y=edges[i].second;
            if(x == par[y])Update(in[y],-2), Update(out[y],2);
            else Update(in[x],-2), Update(out[x],2);
        }
        else
        {
            cin >> x >> y;
            if(tag[x] == tag[y])
            {
                if(dist[x] <= dist[y])
                {
                    if(Query(in[y])-Query(in[x]) == dist[y]-dist[x])cout << dist[y]-dist[x] << '\n';
                    else cout << "-1\n";
                }
                else
                {
                    if(Query(in[x])-Query(in[y]) == dist[x]-dist[y])cout << dist[x]-dist[y] << '\n';
                    else cout << "-1\n";
                }
            }
            else
            {
                if(Query(in[x]) + Query(in[y])-2 == dist[x] + dist[y])cout << dist[x]+dist[y] << '\n';
                else cout << "-1\n";
            }
        }
    }
    return 0;
}