#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N+2];
vector<long long>visitedTimes;
long long n,primeFacts[N],sz[N+2];
void DFS(int cur,int par)
    sz[cur]=1;
    for(int x : adj[cur])
    {
        if(x ^ par)
        {
            DFS(x,cur);
            sz[cur]+=sz[x];
        }
    }
    if(par)visitedTimes.emplace_back(sz[cur]*(n-sz[cur]));
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,t,x,y;
    long long ans,mod=1e9+7;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        visitedTimes.clear();
        DFS(1,0);
        cin >> m;
        for(i=1;i<=m;i++)cin >> primeFacts[i];
        sort(primeFacts+1,primeFacts+m+1);
        sort(visitedTimes.begin(),visitedTimes.end());
        while(m > n-1)primeFacts[m-1]=(primeFacts[m-1]*primeFacts[m])%mod,m--;
        ans=0;
        for(i=n-2;i>=0;i--)
        {
            if(m == 0)ans+=visitedTimes[i];
            else ans+=(visitedTimes[i]%mod*primeFacts[m])%mod,m--;
            ans%=mod;
        }
        cout << ans << '\n';
    }
    return 0;
}