#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long cnt;
bool mark[505];
int mnDist,a[N+2],dist[N+2];
vector<int>primes,adj[N+2],powers[502];
void Sieve()
{
    int i,j;
    primes.emplace_back(2);
    for(i=3;i<500;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i;j<500;j+=2*i)mark[j]=1;
        }
    }
}
void DFS(int cur,int par)
{
    dist[cur]=dist[par]+1;
    cnt+=(int)powers[a[cur]].size();
    if(!powers[a[cur]].empty())mnDist=min(mnDist,dist[cur]-powers[a[cur]].back());
    powers[a[cur]].emplace_back(dist[cur]);
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
    }
    powers[a[cur]].pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    Sieve();
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            adj[i].clear();
            x=1;
            for(int z : primes)
            {
                if(a[i] < z)break;
                if(a[i]%z == 0)
                {
                    y=0;
                    while(a[i]%z == 0)a[i]/=z,++y;
                    if(y & 1)x*=z;
                }
            }
            a[i]=x;
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        cnt=0,mnDist=INT_MAX;
        for(i=1;i<501;i++)powers[i].clear();
        DFS(1,0);
        if(cnt == 0)cout << "0\n";
        else cout << cnt << ' ' << mnDist << '\n';
    }
    return 0;
}