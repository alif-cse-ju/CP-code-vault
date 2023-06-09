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
    LL bal[200005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,k,ans=0;
    LL a,b,x;
    cin >> n >> a >> b >> k;
    for(i=1;i<=n;i++)cin >> bal[i];
    V<LL>v;
    for(i=1;i<=n;i++)
    {
        if(bal[i]%(a+b) > 0  &&  bal[i]%(a+b) <= a)++ans;
        else
        {
            if(bal[i]%(a+b) == 0)v.PSB(b);
            else v.PSB((bal[i]%(a+b))-a);
        }
    }
    sort(v.B,v.E);
    n=v.SZ;
    for(i=0;i<n;i++)
    {
        x=v[i]/a+(v[i]%a > 0);
        if(x <= k)++ans,k-=x;
        else break;
    }
    cout << ans;
    return 0;
}