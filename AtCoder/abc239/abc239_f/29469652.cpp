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

int deg[M],degSum[M],par[M];
priority_queue<pair<int,int>>child[M];

int FindPar(int x)
{
    if(par[x] == x)return x;
    return par[x]=FindPar(par[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok=1;
    int i,j,l,m,n,px,py,sum=0,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> deg[i], par[i]=i;
    for(i=0;i<m;i++)
    {
        cin >> x >> y;
        px=FindPar(x);
        py=FindPar(y);
        if(px == py)ok=0;
        else par[py]=px, --deg[x], --deg[y];
    }
    if(!ok)
    {
        cout << "-1";
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(deg[i] < 0)
        {
            cout << "-1";
            return 0;
        }
        px=FindPar(i);
        degSum[px] += deg[i];
        child[px].emplace(deg[i],i);
    }
    vector<pair<int,int>>ans;
    priority_queue<pair<int,int>>pq;
    for(i=1;i<=n;i++)
    {
        if(degSum[i])sum += degSum[i], pq.emplace(degSum[i],i);
    }
    l=(int)pq.size();
    if((sum & 1)  ||  l == 1  ||  l+l-2 != sum)
    {
        cout << "-1";
        return 0;
    }
    while((int)pq.size() > 1)
    {
        auto [v1,x1]=pq.top();pq.pop();
        auto [v2,x2]=pq.top();pq.pop();
        sum -= 2, --v1, --v2;
        if(v1+v2)pq.emplace(v1+v2,x1);
        ans.emplace_back(child[x1].top().second, child[x2].top().second);
        auto [v3,x3]=child[x1].top();child[x1].pop();
        if(--v3)child[x1].emplace(v3,x3);
        auto [v4,x4]=child[x2].top();child[x2].pop();
        if(--v4)child[x2].emplace(v4,x4);
        while(!child[x2].empty())child[x1].emplace(child[x2].top()), child[x2].pop();
    }
    if(sum)
    {
        cout << "-1";
        return 0;
    }
    for(auto [x,y] : ans)cout << x << ' ' << y << '\n';
    return 0;
}
