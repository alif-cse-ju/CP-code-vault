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

const int magic = 320;

bool heavy[M];
vector<int>adj[M],heavyAdj[M];
int ans[M],deg[M],updateTime[M],val[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,q;cin >> n >> m >> q;
    for(int i=1;i<=n;i++)ans[i]=val[i]=i;
    while(m--)
    {
        int x,y;cin >> x >> y;
        ++deg[x], ++deg[y];
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        heavy[i] = (deg[i] >= magic);
        if(!heavy[i])continue;
        for(int y : adj[i])
        {
            if(deg[y] >= magic)heavyAdj[i].emplace_back(y);
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x;cin >> x;
        if(!heavy[x])
        {
            int id, mx=0;
            for(int y : adj[x])
            {
                if(heavy[y])
                {
                    if(mx < updateTime[y])id=y, mx=updateTime[y];
                }
            }
            if(mx > updateTime[x])ans[x]=val[x]=val[id];
            updateTime[x]=i;
            for(int y : adj[x])
            {
                if(!heavy[y])ans[y]=val[y]=val[x], updateTime[y]=i;
                else ans[y]=val[x];
            }
        }
        else
        {
            val[x]=ans[x], updateTime[x]=i;
            for(int y : heavyAdj[x])ans[y]=val[x];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!heavy[i])
        {
            int id, mx=updateTime[i];
            for(int y : adj[i])
            {
                if(heavy[y])
                {
                    if(mx < updateTime[y])id=y, mx=updateTime[y];
                }
            }
            if(mx > updateTime[i])ans[i]=val[id];
        }
        cout << ans[i] << ' ';
    }
    return 0;
}