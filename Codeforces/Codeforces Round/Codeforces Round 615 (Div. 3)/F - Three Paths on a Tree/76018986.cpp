#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
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
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
    V<int>adj[200005];
int par[200005],dist[200005];
PQ<PII,V<PII>,greater<PII> >pq;
 void runBFS()
{
    int x,cost;
    while(!pq.EM)
    {
        x=pq.T.SE;
        cost=pq.T.FI;
        pq.PP;
        for(int y : adj[x])
        {
            if(dist[y] > cost+1)
            {
                par[y]=x;
                dist[y]=cost+1;
                pq.emplace(dist[y],y);
            }
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x,y,z,ans=0,mx=-1;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        dist[i+1]=INT_MAX;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    pq.emplace(0,1);
    runBFS();
    for(i=2;i<=n;i++)
    {
        if(dist[i] > ans)x=i,ans=dist[i];
    }
    for(i=1;i<=n;i++)dist[i]=INT_MAX;
    par[x]=x;
    ans=dist[x]=0;
    pq.emplace(0,x);
    runBFS();
    for(i=1;i<=n;i++)
    {
        if(dist[i] > ans)y=i,ans=dist[i];
    }
    if(ans == n-1)
    {
        cout << ans << '\n';
        if(x != 1  &&  y != 1)cout << "1 " << x << ' ' << y;
        else if(x != 2  &&  y != 2)cout << "2 " << x << ' ' << y;
        else cout << "3 " << x << ' ' << y;
        return 0;
    }
    V<int>bal;
    z=y;
    while(z != par[z])
    {
        bal.emplace_back(z);
        z=par[z];
    }
    for(i=1;i<=n;i++)dist[i]=INT_MAX;
    pq.emplace(0,x);dist[x]=0;
    for(int node : bal)pq.emplace(0,node),dist[node]=0;
    runBFS();
    for(i=1;i<=n;i++)
    {
        if(dist[i] > mx)z=i,mx=dist[i];
    }
    cout << ans+mx << '\n';
    cout << x << ' ' << y << ' ' << z;
    return 0;
}