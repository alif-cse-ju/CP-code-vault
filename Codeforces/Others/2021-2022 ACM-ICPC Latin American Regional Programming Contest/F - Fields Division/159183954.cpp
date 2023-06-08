#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char ans[M];
int _max[M],par[M];
vector<int>nodes[M];
int FindParent(int n)
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)ans[i]='A', _max[i]=par[i]=i, nodes[i].emplace_back(i);
    vector<pair<int,int>>edges;
    while(m--)
    {
        int x,y;cin >> x >> y;
        if(x == n  ||  y == n)continue;
        int px=FindParent(x);
        int py=FindParent(y);
        if(px == py)continue;
        if((int)nodes[px].size() >= (int)nodes[py].size())
        {
            par[py]=px, _max[px]=max(_max[px], _max[py]);
            while(!nodes[py].empty())nodes[px].emplace_back(nodes[py].back()), nodes[py].pop_back();
        }
        else
        {
            par[px]=py, _max[py]=max(_max[py], _max[px]);
            while(!nodes[px].empty())nodes[py].emplace_back(nodes[px].back()), nodes[px].pop_back();
        }
    }
    int mx=0,id;
    for(int i=1;i<n;i++)
    {
        int p=FindParent(i);
        if(_max[p] > mx)mx=_max[p], id=p;
    }
    for(int it : nodes[id])ans[it]='B';
    for(int i=1;i<=n;i++)cout << ans[i];
    return 0;
}