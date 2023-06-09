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
    int m,n,k,t;
V<int>a,d,l,r;
 bool check(int idx)
{
    int mn=a[max(0,idx-1)];
    V<PII>seg;
    for(int i=0;i<k;i++)
    {
        if(d[i] > mn)seg.PSB({l[i],r[i]});
    }
    sort(seg.B,seg.E);
    int ans=0,lastr=0;
    for(PII s : seg)
    {
        if(s.FI <= lastr)
        {
            ans+=max(0,s.SE-lastr);
            lastr=max(s.SE,lastr);
        }
        else
        {
            ans+=s.SE-s.FI+1;
            lastr=s.SE;
        }
    }
    ans=2*ans+n+1;
    return ans<=t;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i;
    cin >> m >> n >> k >> t;
    a.resize(m);
    for(i=0;i<m;i++)cin >> a[i];
    sort(a.B,a.E);
    reverse(a.B,a.E);
    d.resize(k),l.resize(k),r.resize(k);
    for(i=0;i<k;i++)cin >> l[i] >> r[i] >> d[i];
    int low=0,mid,high=m+1;
    while(high-low > 1)
    {
        mid=(low+high) >> 1;
        if(check(mid))low=mid;
        else high=mid;
    }
    cout << low;
    return 0;
}