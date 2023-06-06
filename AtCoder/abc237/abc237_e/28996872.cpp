#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int M=2e5+5;

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