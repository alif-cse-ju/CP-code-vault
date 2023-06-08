#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
const int sz = 1e4+5;
int par[sz],sum[sz],_size[sz];
int FindParent(int p)
    if(par[p] == p)return p;
    return par[p]=FindParent(par[p]);
int main()
    int m,n;scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)par[i]=i, _size[i]=1, scanf("%d",&sum[i]);
    while(m--)
    {
        int x,y;scanf("%d %d",&x,&y);
        int px=FindParent(x), py=FindParent(y);
        if(px != py)
        {
            if(_size[px] >= _size[py])par[py]=px, _size[px] += _size[py], sum[px] += sum[py];
            else par[px]=py, _size[py] += _size[px], sum[py] += sum[px];
        }
    }
    bool ok=1;
    for(int i=0;i<n;i++)ok &= (sum[FindParent(i)] == 0);
    if(ok)printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}