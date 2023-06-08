#pragma GCC optimize("Ofast")
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
struct Edge
    int l,r,w;
edges[M];
vector<int>adj[M],queries[M];
int ans[M],par[M],ql[M],qr[M];
void Init(const int& n)
    for(int i=1;i<=n;i++)par[i]=i;
int FindParent(int n)
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].emplace_back(i);
        adj[y].emplace_back(i);
        edges[i].l=x, edges[i].r=y, edges[i].w=z;
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        ans[i]=2;
        cin >> ql[i] >> qr[i];
        queries[ql[i]].emplace_back(i);
    }
    for(int i=0;i<31;i++)
    {
        Init(n);
        for(int j=1;j<=m;j++)
        {
            if(!((edges[j].w >> i) & 1))continue;
            int px=FindParent(edges[j].l);
            int py=FindParent(edges[j].r);
            if(px != py)par[py]=px;
        }
        for(int j=1;j<=q;j++)
        {
            int px=FindParent(ql[j]);
            int py=FindParent(qr[j]);
            if(px == py)ans[j]=0;
        }
        if(!i)continue;
        vector<int>connected[n+1];
        for(int j=1;j<=n;j++)connected[FindParent(j)].emplace_back(j);
        for(int j=1;j<=n;j++)
        {
            if(connected[j].empty())continue;
            bool evenEdge=false;
            for(int x : connected[j])
            {
                for(int id : adj[x])
                {
                    if(!(edges[id].w%2))
                    {
                        evenEdge=true;
                        break;
                    }
                }
                if(evenEdge)break;
            }
            if(!evenEdge)continue;
            for(int x : connected[j])
            {
                for(int id : queries[x])
                {
                    if(ans[id])ans[id]=1;
                }
            }
        }
    }
    for(int i=1;i<=q;i++)cout << ans[i] << '\n';
    return 0;
}