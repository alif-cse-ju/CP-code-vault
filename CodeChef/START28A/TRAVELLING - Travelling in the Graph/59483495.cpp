#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
queue<int>q;
vector<int>pos[M];
int a[M],ans[M],n,par[M];
int FindPar(int n)
{
    if(par[n] == n)return n;
    return par[n]=FindPar(par[n]);
}
void BFS()
{
    int v,x,y;
    while(!q.empty())
    {
        x=q.front(), q.pop();
        v=ans[a[x]]+1, y=x-1;
        if(y && ans[a[y]] > v)
        {
            ans[a[y]]=v;
            for(int it : pos[a[y]])q.emplace(it);
        }
        y=x+1;
        if(y <= n && ans[a[y]] > v)
        {
            ans[a[y]]=v;
            for(int it : pos[a[y]])q.emplace(it);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,px,py,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)par[i]=i, pos[i].clear();
        while(m--)
        {
            cin >> x >> y;
            px=FindPar(x), py=FindPar(y);
            if(px != py)
            {
                if(px < py)par[py]=px;
                else par[px]=py;
            }
        }
        for(i=1;i<=n;i++)a[i]=FindPar(i), ans[i]=1e9;
        for(i=1;i<=n;i++)
        {
            pos[a[i]].emplace_back(i);
            if(a[i] == 1)ans[i]=0, q.emplace(i);
        }
        BFS();
        cout << ans[a[n]] << '\n';
    }
    return 0;
}