#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;
const int sz = 1e5+5;
int bridgeCnt, lcaIteration, dsuCC[sz], dsuCCSize[sz], dsu2ECC[sz], lastVisit[sz], par[sz];
void Init(const int& n)
    bridgeCnt = lcaIteration = 0;
    for(int i=1;i<=n;i++)
    {
        dsuCC[i] = dsu2ECC[i] = i;
        par[i]=-1, lastVisit[i]=0, dsuCCSize[i]=1;
    }
int Find2ECC(int x)
{
    if(x == -1)return x;
    return (dsu2ECC[x] == x) ? x : dsu2ECC[x] = Find2ECC(dsu2ECC[x]);
}
 int FindCC(int x)
{
    x = Find2ECC(x);
    return (dsuCC[x] == x) ? x : dsuCC[x] = FindCC(dsuCC[x]);
}
 void MakeRoot(int x)
{
    x = Find2ECC(x);
    int root = x, child = -1;
    while(x != -1)
    {
        int p = Find2ECC(par[x]);
        par[x] = child, dsuCC[x] = root, child = x, x = p;
    }
    dsuCCSize[root] = dsuCCSize[child];
}
 void MergePath(int a, int b)
{
    ++lcaIteration;
    vector<int>pathA, pathB;
    int lca = -1;
    while(lca == -1)
    {
        if(a != -1)
        {
            a = Find2ECC(a);
            pathA.emplace_back(a);
            if(lastVisit[a] == lcaIteration)
            {
                lca = a;
                break;
            }
            lastVisit[a] = lcaIteration;
            a = par[a];
        }
        if(b != -1)
        {
            b = Find2ECC(b);
            pathB.emplace_back(b);
            if(lastVisit[b] == lcaIteration)
            {
                lca = b;
                break;
            }
            lastVisit[b] = lcaIteration;
            b = par[b];
        }
    }
    for(int x : pathA)
    {
        dsu2ECC[x] = lca;
        if(x == lca)break;
        --bridgeCnt;
    }
    for(int x : pathB)
    {
        dsu2ECC[x] = lca;
        if(x == lca)break;
        --bridgeCnt;
    }
}
 void AddEdge(int a,int b)
{
    a = Find2ECC(a), b = Find2ECC(b);
    if(a == b)return;
    int ca = FindCC(a), cb = FindCC(b);
    if(ca != cb)
    {
        ++bridgeCnt;
        if(dsuCCSize[ca] > dsuCCSize[cb])swap(a, b), swap(ca, cb);
        MakeRoot(a);
        par[a] = dsuCC[a] = b, dsuCCSize[cb] += dsuCCSize[a];
    }
    else MergePath(a, b);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("bridges.in","r",stdin);
    freopen("bridges.out","w",stdout);
    int m,n;cin >> n >> m;
    Init(n);
    while(m--)
    {
        int x,y;cin >> x >> y;
        AddEdge(x,y);
    }
    int q;cin >> q;
    while(q--)
    {
        int x,y;cin >> x >> y;
        AddEdge(x,y);
        cout << bridgeCnt << '\n';
    }
    return 0;
}