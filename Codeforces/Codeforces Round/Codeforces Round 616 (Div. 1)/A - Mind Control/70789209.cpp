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
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int a[3505],i,j,k,m,n,t,sz,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i=0;i<n;i++)cin >> a[i];
        k=min(k,m-1);
        V<int>v;
        for(i=0;i<m;i++)v.PSB(max(a[i],a[i+n-m]));
        sz=m-k,ans=0;
        DQ<int>dq;
        for(i=j=0;i+sz-1<m;i++)
        {
            while(!dq.EM  &&  dq.F < i)dq.PPF;
            while(j < i+sz)
            {
                while(!dq.EM  &&  v[dq.back()] >= v[j])dq.PPB;
                dq.PSB(j++);
            }
            ans=max(ans,v[dq.F]);
        }
        cout << ans << '\n';
    }
    return 0;
}