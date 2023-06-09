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
      LL i,j,n,l,x,y,mn,mx,check=0;
    cin >> n;
    V<LL>v[n+2];
    V<PLL>temp;
    for(i=1;i<=n;i++)
    {
        cin >> l;
        while(l--)
        {
            cin >> x;
            v[i].PSB(x);
        }
    }
    V<LL>mx_ache;
    LL ans=0LL;check=n;
    for(i=1;i<=n;i++)
    {
        mx=-1;
        for(j=(LL)v[i].SZ-1;j>=0;j--)
        {
            if(v[i][j] >= mx)mx=v[i][j];
            else
            {
                ans+=(check*2LL-1LL);
                --check;
                break;
            }
        }
        if(j < 0LL)
        {
            temp.PSB({v[i].back(),v[i][0]});
            mx_ache.PSB(mx);
        }
    }
    sort(mx_ache.B,mx_ache.E);
    for(PII bal : temp)
    {
        x=bal.FI;
        check=(LL)(upper_bound(mx_ache.B,mx_ache.E,x)-mx_ache.B);
        check=(LL)mx_ache.SZ-check;
        ans+=check;
    }
    cout << ans;
    return 0;
}