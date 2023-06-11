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
LL nCr(LL n,LL k)
{
    int j;
    V<LL>v;
    LL i,a=max(k,n-k),b=n-a,fact=1;
    for(i=2; i<=b; i++)
    {
        v.PSB(i);
    }
    for(i=a+1; i<=n; i++)
    {
        fact*=i;
        for(j=0; j<int(v.SZ); j++)
        {
            if(fact%v[j] == 0)
            {
                fact/=v[j];
                v[j]=1;
            }
        }
    }
    return fact;
}
int main()
{
//    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    int t;
    LL n,k;
    S("%d",&t);
    while(t--)
    {
        S("%lld %lld",&n,&k);
        P("%lld\n",nCr(n-1,k-1));
    }
    return 0;
}