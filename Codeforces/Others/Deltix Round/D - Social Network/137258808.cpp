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
const int M=1e3+5;
const int N=1e6+5;
const int mod=1e9+7;
int par[M],sz[M];
pair<int,int>queries[M];
int Par(int p)
    if(par[p] == p)return p;
    return par[p]=Par(par[p]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt,i,id,j,k,mx,n,px,py,q;
    cin >> n >> q;
    for(i=1;i<=q;i++)cin >> queries[i].first >> queries[i].second;
    for(i=1;i<=q;i++)
    {
        cnt=0;
        for(j=1;j<=n;j++)par[j]=j, sz[j]=1;
        for(k=1;k<=i;k++)
        {
            auto [x,y]=queries[k];
            px=Par(x), py=Par(y);
            if(px != py)par[py]=px, sz[px] += sz[py];
            else ++ cnt;
        }
        mx=0;
        for(j=1;j<=n;j++)
        {
            if(sz[j] > mx)mx=sz[j], px=j;
        }
        while(cnt--)
        {
            id=mx=0;
            for(j=1;j<=n;j++)
            {
                py=Par(j);
                if(py != px  &&  sz[py] > mx)mx=sz[py], id=py;
            }
            par[id]=px, sz[px]+=sz[id];
        }
        mx=0;
        for(j=1;j<=n;j++)mx=max(mx,sz[j]);
        cout << mx-1 << '\n';
    }
    return 0;
}