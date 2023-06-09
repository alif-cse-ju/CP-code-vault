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
#define PSB emplace_back
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
PQ<PII,V<PII>,greater<PII> >pq;
int a[200005],dist1[200005],dist2[200005];
 void run_bfs(int *dist)
{
    int x,cost;
    while(!pq.EM)
    {
        cost=pq.T.FI;
        x=pq.T.SE;
        pq.PP;
        for(int y : adj[x])
        {
            if(dist[y] > cost+1)
            {
                dist[y]=cost+1;
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
     int i,k,m,n,x,y,ans=0,cur=INT_MIN;
    cin >> n >> m >> k;
    for(i=1;i<=k;i++)cin >> a[i];
    while(m--)
    {
        cin >> x >> y;
        adj[x].PSB(y);
        adj[y].PSB(x);
    }
    for(i=1;i<=n;i++)dist1[i]=dist2[i]=INT_MAX;
    dist1[1]=0;
    pq.PS({0,1});
    run_bfs(dist1);
    dist2[n]=0;
    pq.PS({0,n});
    run_bfs(dist2);
     sort(a+1,a+k+1,[](int x,int y){return dist1[x]+dist2[y] < dist1[y]+dist2[x];});
     for(i=1;i<=k;i++)
    {
        x=a[i];
        ans=max(ans,dist2[x]+cur+1);
        cur=max(cur,dist1[x]);
    }
    cur=INT_MIN;
    for(i=k;i>0;i--)
    {
        x=a[i];
        ans=max(ans,dist1[x]+cur+1);
        cur=max(cur,dist2[x]);
    }
    cout << min(ans,dist1[n]);
    return 0;
}