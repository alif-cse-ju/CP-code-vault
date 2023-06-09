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
    bool compare(PLL x,PLL y)
{
    if(x.FI == y.FI)return x.SE > y.SE;
    return x.FI > y.FI;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n;
    LL x,y,ans;
    cin >> n;
    PLL lands[n];
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        lands[i].FI=min(x,y);
        lands[i].SE=max(x,y);
    }
    sort(lands,lands+n,compare);
    ans=lands[0].FI*lands[0].SE,x=lands[0].SE;
    for(i=1;i<n;i++)
    {
        ans=max(ans,lands[i].FI*lands[i].SE);
        y=min(x,lands[i].SE);
        ans=max(ans,lands[i].FI*y*2);
        x=max(x,lands[i].SE);
    }
    cout << ans/2;
    if(ans & 1)cout << ".5";
    else cout << ".0";
    return 0;
}