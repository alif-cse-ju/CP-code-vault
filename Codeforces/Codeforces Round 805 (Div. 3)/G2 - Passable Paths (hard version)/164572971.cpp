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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
///LCA
vector<int>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
    inTime[cur]=++timer;
    up[cur][0]=par;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
    }
    outTime[cur]=++timer;
}
 bool IsAncestor(int x,int y)
{
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
 void PreProcess(int numberOfNodes)
{
    l=ceil(log2(numberOfNodes));
    DFS(1,1);
}
 ///LCA
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<n;i++)
    {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
    }
    PreProcess(n);
    int q;cin >> q;
    for(int qc=1;qc<=q;qc++)
    {
            int k;cin >> k;
            vector<int>v(k);
            vector<bool>mark(k, 0);
            for(int &x : v)cin >> x;
            int x1=v[0];
            for(int &y : v)
            {
                    if(inTime[x1] < inTime[y])x1=y;
            }
            int kk=k;
            for(int i=0;i<k;i++)
            {
                    if(inTime[v[i]] <= inTime[x1]  &&  outTime[v[i]] >= outTime[x1])mark[i]=1, --kk;
            }
            if(!kk)cout << "YES\n";
            else
            {
                    int x2=0;
                    for(int i=0;i<k;i++)
                    {
                            if(!mark[i])
                            {
                                    if(!x2  ||  inTime[x2] < inTime[v[i]])x2=v[i];
                            }
                    }
                    bool ok=1;
                    for(int i=0;i<k;i++)
                    {
                            if(!mark[i])ok = ok & ((inTime[v[i]] <= inTime[x2])  &  (outTime[v[i]] >= outTime[x2]));
                    }
                    int lca=LCA(x1,x2);
                    if(ok)
                    {
                            for(int &y : v)ok = ok & (!(inTime[y] < inTime[lca]));
                    }
                    if(ok)cout << "YES\n";
                    else cout << "NO\n";
            }
    }
    return 0;
}