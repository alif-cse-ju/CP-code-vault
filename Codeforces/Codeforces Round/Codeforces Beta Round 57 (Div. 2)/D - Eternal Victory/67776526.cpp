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
    LL dist[100002];
V<PII>adj[100002];
PQ<PLI,V<PLI>,greater<PLI> >pq;
 void run_dijkstra()
{
    int i,l,x,y;
    LL val,z;
    while(!pq.EM)
    {
        x=pq.T.SE;
        val=pq.T.FI;
        pq.PP;
        l=adj[x].SZ;
        for(i=0;i<l;i++)
        {
            y=adj[x][i].FI;
            z=adj[x][i].SE;
            if(dist[y] > val+z)
            {
                dist[y]=val+z;
                pq.PS({dist[y],y});
            }
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x,y,z;
    LL ans=0LL,mx=0LL;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cin >> x >> y >> z;
        adj[x].PSB({y,z});
        adj[y].PSB({x,z});
        dist[i]=1e18;
        ans+=(z*2LL);
    }
    pq.PS({0LL,1});
    run_dijkstra();
    for(i=2;i<=n;i++)mx=max(mx,dist[i]);
    cout << ans-mx;
    return 0;
}