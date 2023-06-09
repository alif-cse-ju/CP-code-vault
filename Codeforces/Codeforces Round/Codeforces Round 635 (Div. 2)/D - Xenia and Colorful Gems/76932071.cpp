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
    LL ans;
 LL Check(LL x,LL y,LL z)
{
    return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}
 void FindAns(V<LL>&a,V<LL>&b,V<LL>&c)
{
    for(LL x : a)
    {
        auto lb=lower_bound(b.B,b.E,x);
        auto lc=lower_bound(c.B,c.E,x);
        V<LL>optB,optC;
        if(lb != b.E)optB.emplace_back(*(lb));
        if(lb != b.B)optB.emplace_back(*(--lb));
        if(lc != c.E)optC.emplace_back(*(lc));
        if(lc != c.B)optC.emplace_back(*(--lc));
        for(LL y : optB)
        {
            for(LL z : optC)ans=min(ans,Check(x,y,z));
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,k,t,x,a[3];
    cin >> t;
    while(t--)
    {
        V<LL>v[3];
        cin >> a[0] >> a[1] >> a[2];
        for(i=0;i<3;i++)
        {
            for(j=0;j<a[i];j++)
            {
                cin >> x;
                v[i].emplace_back(x);
            }
            sort(v[i].B,v[i].E);
        }
        ans=5e18;
        for(i=0;i<3;i++)
        {
            j=(i+1)%3;
            k=(i+2)%3;
            FindAns(v[i],v[j],v[k]);
        }
        cout << ans << '\n';
    }
    return 0;
}