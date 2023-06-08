#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int dist[N];
long long ans;
vector<int>adj[N];
priority_queue<pair<int,int>>pq[N];
void DFS(int cur,int val)
    dist[cur]=val;
    if(adj[cur].empty())pq[cur].emplace(-dist[cur],cur),ans+=val;
    else
    {
        ++val;
        for(int it : adj[cur])
        {
            DFS(it,val);
            while(!pq[it].empty())
            {
                pq[cur].emplace(pq[it].top());
                pq[it].pop();
            }
        }
        pair<int,int>temp;
        while((int)pq[cur].size() > 1)
        {
            temp=pq[cur].top();
            if((-temp.first)-dist[cur] < dist[cur])
            {
                ans-=dist[cur];
                ans+=(-temp.first)-dist[cur];
                pq[cur].pop();
            }
            else break;
        }
    }
}
 int main()
{
    FAST();
    int i,n,t,tc,x;
    cin >> t;
    for(tc=1;tc<=t;tc++)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            dist[i]=0;
            adj[i].clear();
            while(!pq[i].empty())pq[i].pop();
        }
        for(i=2;i<=n;i++)
        {
            cin >> x;
            adj[x].emplace_back(i);
        }
        ans=0;
        DFS(1,0);
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;
}