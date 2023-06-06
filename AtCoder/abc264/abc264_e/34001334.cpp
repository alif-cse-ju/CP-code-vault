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

const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;

bool mark[M];
pair<int,int>edges[M];
ordered_set<int>ost[M];
int finalAns[M],par[M],queries[M];

int FindParent(int p)
{
    if(par[p] == p)return p;
    return par[p]=FindParent(par[p]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e,m,n;cin >> n >> m >> e;
    for(int i=1;i<=m+n;i++)par[i]=i, ost[i].insert(i);
    for(int i=1;i<=e;i++)
    {
        int x,y;cin >> x >> y;
        edges[i]={x,y};
    }
    int q;cin >> q;
    for(int i=1;i<=q;i++)cin >> queries[i], mark[queries[i]]=1;
    int ans=0;
    for(int i=1;i<=e;i++)
    {
        if(!mark[i])
        {
            auto [x,y]=edges[i];
            int px=FindParent(x), py=FindParent(y);
            if(px != py)
            {
                int xN=ost[px].order_of_key(n+1);
                int yN=ost[py].order_of_key(n+1);
                if(xN == (int)ost[px].size()  &&  yN < (int)ost[py].size())ans += xN;
                else if(xN < (int)ost[px].size()  &&  yN == (int)ost[py].size())ans += yN;

                if((int)ost[px].size() >= (int)ost[py].size())
                {
                    par[py]=px;
                    for(int it : ost[py])ost[px].insert(it);
                    ost[py].clear();
                }
                else
                {
                    par[px]=py;
                    for(int it : ost[px])ost[py].insert(it);
                    ost[px].clear();
                }
            }
        }
    }
    for(int i=q;i;i--)
    {
        finalAns[i]=ans;
        auto [x,y]=edges[queries[i]];
        int px=FindParent(x), py=FindParent(y);
        if(px != py)
        {
            int xN=ost[px].order_of_key(n+1);
            int yN=ost[py].order_of_key(n+1);
            if(xN == (int)ost[px].size()  &&  yN < (int)ost[py].size())ans += xN;
            else if(xN < (int)ost[px].size()  &&  yN == (int)ost[py].size())ans += yN;

            if((int)ost[px].size() >= (int)ost[py].size())
            {
                par[py]=px;
                for(int it : ost[py])ost[px].insert(it);
                ost[py].clear();
            }
            else
            {
                par[px]=py;
                for(int it : ost[px])ost[py].insert(it);
                ost[px].clear();
            }
        }
    }
    for(int i=1;i<=q;i++)cout << finalAns[i] << '\n';
    return 0;
}
