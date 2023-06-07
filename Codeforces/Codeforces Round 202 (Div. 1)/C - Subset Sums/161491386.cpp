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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int maxSize = 320;

int sz[M];
vector<int>Sets[M],boroSet[M];
ll a[M],setUpdate[M],setSum[M];
map<int,int>boroBoroCnt[M],chotoBoroCnt[M];

//boroSet stores i-th index occurs in which boro sets.
//chotoBoroCnt[i][j] stores common elements between choto set(i) and boro set(j)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,q;cin >> n >> m >> q;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=m;i++)
    {
        cin >> sz[i];
        for(int j=0;j<sz[i];j++)
        {
            int x;cin >> x;
            setSum[i] += a[x];
            Sets[i].emplace_back(x);
        }
        if(sz[i] > maxSize)
        {
            for(int it : Sets[i])
            {
                for(int it1 : boroSet[it])++boroBoroCnt[i][it1], ++boroBoroCnt[it1][i];
                boroSet[it].emplace_back(i);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(sz[i] <= maxSize)
        {
            for(int it1 : Sets[i])
            {
                for(int it2 : boroSet[it1])++chotoBoroCnt[i][it2];
            }
        }
    }
    while(q--)
    {
        int k;string t;cin >> t >> k;
        if(t == "+")
        {
            int x;cin >> x;
            if(sz[k] <= maxSize)
            {
                for(int it : Sets[k])a[it] += x;
                for(auto[j,v] : chotoBoroCnt[k])setSum[j] += 1ll*x*v;
            }
            else
            {
                setUpdate[k] += x, setSum[k] += 1ll*sz[k]*x;
            }
        }
        else
        {
            ll ans=0;
            if(sz[k] <= maxSize)
            {
                for(int it : Sets[k])ans += a[it];
                for(auto[j,v] : chotoBoroCnt[k])ans += 1ll*setUpdate[j]*v;
            }
            else
            {
                ans=setSum[k];
                for(auto[j,v] : boroBoroCnt[k])ans += 1ll*setUpdate[j]*v;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
