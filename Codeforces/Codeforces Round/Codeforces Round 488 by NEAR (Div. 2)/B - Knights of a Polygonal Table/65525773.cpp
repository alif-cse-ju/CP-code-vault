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
    PQ<int,V<int>,greater<int> >pq;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,k,x=0;
    LL sum=0;
    cin >> n >> k;
    pair<PII,int> a[n+2];
    LL ans[n+2];
    for(i=0;i<n;i++)cin >> a[i].FI.FI;
    for(i=0;i<n;i++)cin >> a[i].FI.SE,a[i].SE=i;
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(i > k)
        {
            x=pq.T;
            pq.PP;
        }
        sum=sum+a[i].FI.SE-x;
        pq.PS(a[i].FI.SE);
        ans[a[i].SE]=sum;
    }
    for(i=0;i<n;i++)cout << ans[i] << ' ';
    return 0;
}