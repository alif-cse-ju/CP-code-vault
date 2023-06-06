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

int cnt[M];
ll ans[M],H[M];
bool inQueue[M];
vector<int>adj[M];

bool ok=1;
priority_queue<pair<ll,int>>pq;

void DijkstraFirst(const int& n)
{
    while(!pq.empty())
    {
        auto [v,x]=pq.top();
        pq.pop();
        if(cnt[x] > n)
        {
            ok=0;
            return;
        }
        if(ans[x] != v)continue;
        ++cnt[x];
        for(int y : adj[x])
        {
            if(H[x] > H[y]  &&  ans[y] < v+H[x]-H[y])ans[y]=v+H[x]-H[y], pq.emplace(ans[y],y);
            else if(H[x] < H[y]  &&  ans[y] < v+2*(H[x]-H[y]))ans[y]=v+2*(H[x]-H[y]), pq.emplace(ans[y],y);
            else if(H[x] == H[y]  &&  ans[y] < v)ans[y]=v, pq.emplace(ans[y],y);
        }
    }
}

void DijkstraSecond(const int& n)
{
    int x;
    queue<int>q;
    q.emplace(1);
    inQueue[1] = 1;
    while(!q.empty())
    {
        x = q.front(), q.pop(), inQueue[x] = 0;
        for(int y : adj[x])
        {
            if(H[x] > H[y]  &&  ans[y] < ans[x]+H[x]-H[y])
            {
                ans[y]=ans[x]+H[x]-H[y];
                if(!inQueue[y])
                {
                    q.emplace(y), inQueue[y]=1;
                    if(++cnt[y] > n)return;
                }
            }
            else if(H[x] < H[y]  &&  ans[y] < ans[x]+2*(H[x]-H[y]))
            {
                ans[y]=ans[x]+2*(H[x]-H[y]);
                if(!inQueue[y])
                {
                    q.emplace(y), inQueue[y]=1;
                    if(++cnt[y] > n)return;
                }
            }
            else if(H[x] == H[y]  &&  ans[y] < ans[x])
            {
                ans[y]=ans[x];
                if(!inQueue[y])
                {
                    q.emplace(y), inQueue[y]=1;
                    if(++cnt[y] > n)return;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    for(i=1; i<=n; i++)cin >> H[i], ans[i]=LLONG_MIN;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    ans[1]=0;
    pq.emplace(0,1);
    DijkstraFirst(n);
    if(ok)
    {
        sort(ans+1,ans+n+1);
        cout << ans[n];
    }
    else
    {
        for(i=1; i<=n; i++)ans[i]=LLONG_MIN, cnt[i]=0;
        ans[1]=0;
        DijkstraSecond(n);
        sort(ans+1,ans+n+1);
        cout << ans[n];
    }
    return 0;
}