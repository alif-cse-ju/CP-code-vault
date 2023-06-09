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
    LL k,n,heights[30002],temp[30002];
 bool check(LL x)
{
    int i;
    LL cnt=0LL,mod;
    for(i=1;i<=n;i++)temp[i]=heights[i];
    for(i=1;i<n;i++)
    {
        cnt+=(temp[i]/x);
        mod=(temp[i]%x);
        if(temp[i+1] >= (x-mod))++cnt,temp[i+1]-=(x-mod);
    }
    cnt+=(temp[n]/x);
    return (cnt >= k);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,t;
    LL sum,low,mid,high;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        sum=0LL;
        for(i=1;i<=n;i++)cin >> heights[i],sum+=heights[i];
        low=0LL,high=(sum/k)+2LL;
        while(high-low > 1LL)
        {
            mid=(low+high) >> 1LL;
            if(mid*k <= sum  &&  check(mid))low=mid;
            else high=mid;
        }
        cout << low*k << '\n';
    }
    return 0;
}