#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;

bool mark[M];
vector<int>adj[M];
pair<int,int>edge[M];
int a[M],ansNode[M],b[M],cnt,in[M],out[M],par[M];

int FindPar(int x)
{
    return par[x]=(par[x] == x ? x : FindPar(par[x]));
}

void DFS(int x)
{
    in[x]=++cnt;
    for(int &y : adj[x])DFS(y);
    out[x]=cnt;
}

///Seg Tree

int segTree[4*M];

void Build(int n,int l,int r)
{
    if(l == r)
    {
        segTree[n]=l;
        return;
    }
    int m=(l+r) >> 1;
    Build(2*n,l,m), Build(2*n+1,m+1,r);
    segTree[n]=(b[segTree[2*n]] > b[segTree[2*n+1]] ? segTree[2*n] : segTree[2*n+1]);
}

void Update(int n,int s,int e,int id)
{
    if(s == e)
    {
        b[id]=0;
        return;
    }
    int m=(s+e) >> 1;
    if(id <= m)Update(2*n,s,m,id);
    else Update(2*n+1,m+1,e,id);
    segTree[n]=(b[segTree[2*n]] > b[segTree[2*n+1]] ? segTree[2*n] : segTree[2*n+1]);
}

int Query(int n,int s,int e,int l,int r)
{
    if(s >= l  &&  e <= r)return segTree[n];
    int m=(s+e) >> 1;
    if(r <= m)return Query(2*n,s,m,l,r);
    if(l > m)return Query(2*n+1,m+1,e,l,r);
    int L=Query(2*n,s,m,l,r), R=Query(2*n+1,m+1,e,l,r);
    return (b[L] > b[R] ? L : R);
}

///Seg Tree

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,q;cin >> n >> m >> q;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=m;i++)
    {
        int x,y;cin >> x >> y;
        edge[i]={x,y};
    }
    vector<pair<int,int>>queries;
    for(int j=0;j<q;j++)
    {
        int t,i;cin >> t >> i;
        queries.emplace_back(t,i);
        if(t == 2)mark[i]=1;
    }
    int nCnt=n;
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(mark[i])continue;
        auto [x,y]=edge[i];
        int px=FindPar(x), py=FindPar(y);
        if(px == py)continue;
        ++nCnt, par[px]=par[py]=par[nCnt]=nCnt;
        adj[nCnt].emplace_back(px), adj[nCnt].emplace_back(py);
    }
    for(int j=q-1;j>=0;j--)
    {
        auto [t,i]=queries[j];
        if(t == 1)ansNode[j]=FindPar(i);
        else
        {
            auto [x,y]=edge[i];
            int px=FindPar(x), py=FindPar(y);
            if(px == py)continue;
            ++nCnt, par[px]=par[py]=par[nCnt]=nCnt;
            adj[nCnt].emplace_back(px), adj[nCnt].emplace_back(py);
        }
    }
    for(int i=1;i<=nCnt;i++)
    {
        if(!in[i])DFS(FindPar(i));
    }
    for(int i=1;i<=nCnt;i++)b[in[i]]=a[i];
    Build(1,1,nCnt);
    for(int i=0;i<q;i++)
    {
        auto [t,x]=queries[i];
        if(t == 1)
        {
            int id=Query(1,1,nCnt,in[ansNode[i]],out[ansNode[i]]);
            cout << b[id] << '\n';
            Update(1,1,nCnt,id);
        }
    }
    return 0;
}
