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
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n,x;
    cin >> n >> m;
    LL a[n+2],c[n+2],y,ans;
    PQ<PLI,V<PLI>,greater<PLI> >pq;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        cin >> c[i];
        pq.emplace(c[i],i);
    }
    while(m--)
    {
        cin >> x >> y;
        ans=0;
        if(a[x] > 0)
        {
            ans+=min(a[x],y)*c[x];
            if(a[x] > y)a[x]-=y,y=0;
            else y-=a[x],a[x]=0;
        }
        if(y > 0)
        {
            while(!pq.EM &&  y)
            {
                ans+=min(a[pq.T.SE],y)*pq.T.FI;
                if(a[pq.T.SE] > y)a[pq.T.SE]-=y,y=0;
                else y-=a[pq.T.SE],a[pq.T.SE]=0,pq.PP;
            }
        }
        if(y > 0)ans=0;
        cout << ans << "\n";
    }
    return 0;
}