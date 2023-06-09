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
    PII heroes[200002];
int monsters[200002];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,m,n,t,x,mx,ans,cnt,mxm,mxh;
    cin >> t;
    while(t--)
    {
        mxm=mxh=0;
        cin >> n;
        for(i=1;i<=n;i++)cin >> monsters[i],mxm=max(mxm,monsters[i]);
        cin >> m;
        for(i=1;i<=m;i++)cin >> heroes[i].FI >> heroes[i].SE,mxh=max(mxh,heroes[i].FI);
        if(mxm > mxh)cout << "-1\n";
        else
        {
            ans=0;
            sort(heroes+1,heroes+m+1);
            V<PII>max_pow;
            max_pow.PSB(heroes[m]);
            for(i=m-1;i>0;i--)
            {
                if(heroes[i].SE > max_pow.back().SE)max_pow.PSB(heroes[i]);
            }
            reverse(max_pow.B,max_pow.E);
            mx=cnt=ans=0;
            for(i=1;i<=n;i++)
            {
                mx=max(mx,monsters[i]);
                ++cnt;
                x=lower_bound(max_pow.B,max_pow.E,MP(mx,-1))-max_pow.B;
                if(max_pow[x].SE < cnt)
                {
                    ++ans,--i;
                    mx=cnt=0;
                }
            }
            cout << ans+1 << '\n';
        }
    }
    return 0;
}