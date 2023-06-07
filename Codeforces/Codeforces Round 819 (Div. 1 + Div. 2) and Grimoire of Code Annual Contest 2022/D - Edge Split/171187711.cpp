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
int ans[M],par[M],sz[M];
pair<int,int>edges[M];
int FindParent(int x)
    if(par[x] == x)return x;
    return par[x]=FindParent(par[x]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
            int x,y;cin >> x >> y;
            ans[i]=2, edges[i]={x,y};
        }
        for(int i=1;i<=n;i++)par[i]=i, sz[i]=1;
        for(int i=1;i<=m;i++)
        {
            auto [x,y] = edges[i];
            int px=FindParent(x), py=FindParent(y);
            if(px != py)
            {
                ans[i]=0;
                if(sz[px] >= sz[py])par[py]=px, sz[px] += sz[py];
                else par[px]=py, sz[py] += sz[px];
            }
            else ans[i]=1;
        }
        for(int i=1;i<=n;i++)par[i]=i, sz[i]=1;
        int id; bool ok=1;
        for(int i=1;i<=m  &&  ok;i++)
        {
            if(!ans[i])continue;
            auto [x,y] = edges[i];
            int px=FindParent(x), py=FindParent(y);
            if(px != py)
            {
                if(sz[px] >= sz[py])par[py]=px, sz[px] += sz[py];
                else par[px]=py, sz[py] += sz[px];
            }
            else id=i, ok=0;
        }
        if(!ok)
        {
            for(int i=1;i<=m;i++)
            {
                if(!ans[i]  ||  i == id)ans[i]=2;
            }
            for(int i=1;i<=n;i++)par[i]=i, sz[i]=1;
            for(int i=id;i;i--)
            {
                if(ans[i] == 1)continue;
                auto [x,y] = edges[i];
                int px=FindParent(x), py=FindParent(y);
                if(px != py)
                {
                    ans[i]=0;
                    if(sz[px] >= sz[py])par[py]=px, sz[px] += sz[py];
                    else par[px]=py, sz[py] += sz[px];
                }
                else ans[i]=1;
            }
            for(int i=id+1;i<=m;i++)
            {
                if(ans[i] == 1)continue;
                auto [x,y] = edges[i];
                int px=FindParent(x), py=FindParent(y);
                if(px != py)
                {
                    ans[i]=0;
                    if(sz[px] >= sz[py])par[py]=px, sz[px] += sz[py];
                    else par[px]=py, sz[py] += sz[px];
                }
                else ans[i]=1;
            }
        }
        for(int i=1;i<=m;i++)cout << ans[i];
        cout << '\n';
    }
    return 0;
}