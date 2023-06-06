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

ll ans[M],H[M];
vector<int>adj[M];
priority_queue<pair<ll,int>>pq;

void Dijkstra()
{
    while(!pq.empty())
    {
        auto [v,x]=pq.top();
        pq.pop();
        for(int y : adj[x])
        {
            if(H[x] > H[y]  &&  ans[y] < v+H[x]-H[y])ans[y]=v+H[x]-H[y], pq.emplace(ans[y],y);
            else if(H[x] < H[y]  &&  ans[y] < v+2*(H[x]-H[y]))ans[y]=v+2*(H[x]-H[y]), pq.emplace(ans[y],y);
            else if(H[x] == H[y]  &&  ans[y] < v)ans[y]=v, pq.emplace(ans[y],y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> H[i], ans[i]=LLONG_MIN;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    ans[1]=0;
    pq.emplace(0,1);
    Dijkstra();
    sort(ans+1,ans+n+1);
    cout << ans[n];
    return 0;
}
