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

vector<int>idx[M];
int ans[M],p[M],par[M];

int FindParent(int x)
{
    if(par[x] == x)return x;
    return par[x]=FindParent(par[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> p[i];
    if(k == 1)
    {
        for(int i=1;i<=n;i++)ans[p[i]]=i;
    }
    else
    {
        for(int i=1;i<=n;i++)ans[i]=-1, par[i]=i;
        ordered_set<pair<int,int>>ost;
        for(int i=1;i<=n;i++)
        {
            int id=ost.order_of_key({p[i],0});
            if(id == (int)ost.size())ost.insert({p[i],1});
            else
            {
                auto [x,y]=*(ost.find_by_order(id));
                ost.erase(ost.find_by_order(id));
                if(y+1 < k)
                {
                    ost.insert({p[i],y+1});
                    int px=FindParent(x);
                    par[p[i]]=px, idx[px].emplace_back(p[i]);
                }
                else
                {
                    int px=FindParent(x);
                    ans[p[i]]=ans[px]=i;
                    for(int &y : idx[px])ans[y]=i;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout << ans[i] << '\n';
    return 0;
}
