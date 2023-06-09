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
   const int n=100005;
V<LL>primes;
bool mark[n];
 void linear_sieve()
{
    LL i,j;
    for(i=2;i<n;i++)
    {
        if(!mark[i])primes.PSB(i);
        for(j=0;i*primes[j] < n;j++)
        {
            mark[i*primes[j]]=1;
            if(i%primes[j] == 0)break;
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     linear_sieve();
    int t;
    LL a,m,ans,gcd;
    cin >> t;
    while(t--)
    {
        cin >> a >> m;
        gcd=__gcd(a,m);
        m/=gcd;
        ans=1;
        for(LL p : primes)
        {
            if(p*p > m)break;
            if(m%p == 0)
            {
                m/=p;
                ans*=(p-1);
                while(m%p == 0)
                {
                    m/=p;
                    ans*=p;
                }
            }
        }
        if(m > 2)ans*=(m-1);
        cout << ans << '\n';
    }
    return 0;
}