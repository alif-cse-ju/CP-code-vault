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
    PII a[102];
V<PII>v;
 bool compare(PII x,PII y)
{
    if(x.FI == y.FI)return x.SE > y.SE;
    return x.FI < y.FI;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i].FI,a[i].SE=i;
    sort(a+1,a+n+1,compare);
    cin >> m;
    while(m--)
    {
        v.C,i=n;
        cin >> x >> y;
        while(x--)v.PSB({a[i].SE,a[i].FI}),--i;
        sort(v.B,v.E);
        cout << v[y-1].SE << '\n';
    }
    return 0;
}