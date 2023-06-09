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
    int a[200005],cnt[400005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,k,n,t,x,y,ans,dhon;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=2*k;i++)cnt[i]=0;
        V<int>mx,mn;
        for(i=1;i<=n/2;i++)
        {
            ++cnt[a[i]+a[n-i+1]];
            mn.PSB(min(a[i],a[n-i+1]));
            mx.PSB(max(a[i],a[n-i+1]));
        }
        ans=INT_MAX;
        sort(mn.B,mn.E);
        sort(mx.B,mx.E);
        for(i=2;i<=2*k;i++)
        {
            dhon=n/2-cnt[i];
            x=upper_bound(mx.B,mx.E,i-k-1)-mx.B;
            y=lower_bound(mn.B,mn.E,i)-mn.B;
            y=n/2-y;
            dhon+=x+y;
            ans=min(ans,dhon);
        }
        cout << ans << "\n";
    }
    return 0;
}