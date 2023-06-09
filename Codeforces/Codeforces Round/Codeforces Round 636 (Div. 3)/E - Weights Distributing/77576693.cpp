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
    Q<int>q;
V<int>adj[200005];
int dist[200005][4];
LL ans,price[200005];
 void runBFS(int id)
{
    int x;
    while(!q.EM)
    {
        x=q.F,q.PP;
        for(int y : adj[x])
        {
            if(dist[y][id] > dist[x][id]+1)
            {
                q.PS(y);
                dist[y][id]=dist[x][id]+1;
            }
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int a,b,c,i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a >> b >> c;
        for(i=1;i<=m;i++)cin >> price[i];
        sort(price+1,price+m+1);
        for(i=2;i<=m;i++)price[i]+=price[i-1];
        for(i=1;i<=n;i++)
        {
            adj[i].C;
            dist[i][1]=dist[i][2]=dist[i][3]=INT_MAX;
        }
        dist[a][1]=dist[b][2]=dist[c][3]=0;
        for(i=1;i<=m;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        ans=1e18;
        q.PS(a);runBFS(1);
        q.PS(b);runBFS(2);
        q.PS(c);runBFS(3);
        for(i=1;i<=n;i++)
        {
            x=dist[i][1]+dist[i][3];
            if(x > m)continue;
            y=dist[i][2];
            if(x+y > m)continue;
            ans=min(ans,price[x+y]+price[y]);
        }
        cout << ans << "\n";
    }
    return 0;
}