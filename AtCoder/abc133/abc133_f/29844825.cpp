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

///LCA
vector<int>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];

void DFS(int cur,int par)
{
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

vector<tuple<int,int,int>>adj2[M];
vector<tuple<int,int,bool>>queries[M];
int ans[M],cntClr[M],cntX[M],dist[M],sumClr[M],sumX[M],Y[M];

void DFS2(int x,int p)
{
    for(auto [c,i,sign] : queries[x])
    {
        if(sign)ans[i] += dist[x], cntX[i] += cntClr[c], sumX[i] += sumClr[c];
        else ans[i] -= dist[x], cntX[i] -= cntClr[c], sumX[i] -= sumClr[c];
    }
    for(auto [y,c,d] : adj2[x])
    {
        if(p ^ y)
        {
            ++cntClr[c], dist[y]=dist[x]+d, sumClr[c] += d;
            DFS2(y, x);
            --cntClr[c], sumClr[c] -= d;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,i,l,n,q,x,y;
    cin >> n >> q;
    for(i=1;i<n;i++)
    {
        cin >> a >> b >> c >> d;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        adj2[a].emplace_back(make_tuple(b,c,d));
        adj2[b].emplace_back(make_tuple(a,c,d));
    }
    PreProcess(n);
    for(i=1;i<=q;i++)
    {
        cin >> c >> Y[i] >> a >> b;
        l=LCA(a,b);
        queries[a].emplace_back(c,i,1);
        queries[b].emplace_back(c,i,1);
        queries[l].emplace_back(c,i,0);
        queries[l].emplace_back(c,i,0);
    }
    DFS2(1,0);
    for(i=1;i<=q;i++)cout << ans[i]-sumX[i]+cntX[i]*Y[i] << '\n';
    return 0;
}