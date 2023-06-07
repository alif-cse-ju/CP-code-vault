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
const int N=1e6+5;
const int mod=1e9+7;

int tag[M];

vector<pair<int,int>>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];

void DFS(int cur,int par)
{
    inTime[cur]=++timer, up[cur][0]=par;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(auto [x,y] : adj[cur])
    {
        if(x ^ par)DFS(x,cur), tag[x]=y;
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

void PreProcess(int numberOfNodes,int root)
{
    l=ceil(log2(numberOfNodes));
    DFS(root,root);
}

int ans[M],dp[M];

void AnswerTaBerKoroTo(int x,int p)
{
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)AnswerTaBerKoroTo(y,x), dp[x]+=dp[y];
    }
    ans[tag[x]]=dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y,i);
        adj[y].emplace_back(x,i);
    }
    PreProcess(n, 1);
    int q;cin >> q;
    while(q--)
    {
        int x,y;cin >> x >> y;
        int l=LCA(x,y); ++dp[x], ++dp[y], dp[l]-=2;
    }
    AnswerTaBerKoroTo(1,1);
    for(int i=1;i<n;i++)cout << ans[i] << ' ';
    return 0;
}