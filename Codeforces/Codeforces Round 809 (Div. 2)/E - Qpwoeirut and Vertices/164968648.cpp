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

set<int>nodes[M];
int laganorTime[M],par[M],_tree[4*M];

int FindParent(int n)
{
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
}

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        _tree[nodeNum]=laganorTime[l];
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    _tree[nodeNum]=max(_tree[2*nodeNum], _tree[2*nodeNum+1]);
}

int Query(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return _tree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    else if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return max(Query(2*nodeNum,start,m,l,r), Query(2*nodeNum+1,m+1,end,l,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n,q;cin >> n >> m >> q;
        for(int i=1;i<=n;i++)par[i]=i, nodes[i].clear(), nodes[i].insert(i);
        for(int i=1;i<=m;i++)
        {
            int x,y;cin >> x >> y;
            int px=FindParent(x), py=FindParent(y);
            if(px == py)continue;
            if((int)nodes[px].size() >= (int)nodes[py].size())
            {
                par[py]=px;
                for(int it : nodes[py])
                {
                    if(nodes[px].find(it-1) != nodes[px].end())laganorTime[it]=i;
                    if(nodes[px].find(it+1) != nodes[px].end())laganorTime[it+1]=i;
                }
                for(int it : nodes[py])nodes[px].insert(it);
            }
            else
            {
                par[px]=py;
                for(int it : nodes[px])
                {
                    if(nodes[py].find(it-1) != nodes[py].end())laganorTime[it]=i;
                    if(nodes[py].find(it+1) != nodes[py].end())laganorTime[it+1]=i;
                }
                for(int it : nodes[px])nodes[py].insert(it);
            }
        }
        Build(1,1,n);
        while(q--)
        {
            int l,r;cin >> l >> r;
            if(l == r)cout << "0 ";
            else cout << Query(1,1,n,l+1,r) << ' ';
        }
        cout << '\n';
    }
    return 0;
}