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
     int i,n,q,x1,x2,y1,y2;
    cin >> n >> q;
    int r[n+1],c[n+1],r_mark[n+1],c_mark[n+1];
    for(i=1;i<=n;i++)cin >> r[i];
    for(i=1;i<=n;i++)cin >> c[i];
    x1=r_mark[1]=1;
    for(i=2;i<=n;i++)
    {
        if(r[i]%2 == r[i-1]%2)r_mark[i]=x1;
        else r_mark[i]=++x1;
    }
    x1=c_mark[1]=1;
    for(i=2;i<=n;i++)
    {
        if(c[i]%2 == c[i-1]%2)c_mark[i]=x1;
        else c_mark[i]=++x1;
    }
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if(r_mark[x1] == r_mark[x2]  &&  c_mark[y1] == c_mark[y2])cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}