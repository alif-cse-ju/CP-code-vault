#include<bits/stdc++.h>
using namespace std;
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
    const int N=1e5+5;
vector<int>adj[N];
int dist[N];
 void DFS(int x,int par)
{
    dist[x]=dist[par]+1;
    for(int y : adj[x])
    {
        if(y ^ par)DFS(y,x);
    }
}
 int main()
{
    FAST();
    int a,b,da,db,i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> da >> db;
        for(i=1;i<=n;i++)adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        if(da >= (db+1)/2)
        {
            cout << "Alice\n";
            continue;
        }
        dist[a]=-1;
        DFS(a,a);
        if(da >= dist[b])
        {
            cout << "Alice\n";
            continue;
        }
        x=0;
        for(i=1;i<=n;i++)
        {
            if(dist[i] > dist[x])x=i;
        }
        dist[x]=-1;
        DFS(x,x);
        y=0;
        for(i=1;i<=n;i++)
        {
            if(dist[i] > dist[y])y=i;
        }
        if(da >= (dist[y]+1)/2)cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}