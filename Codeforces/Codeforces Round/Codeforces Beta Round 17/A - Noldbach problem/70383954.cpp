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
    V<int>primes;
bool mark[1002];
 void sieve()
{
    int i,j;
    primes.PSB(2);
    for(i=4;i<=1000;i+=2)mark[i]=1;
    for(i=3;i<1000;i+=2)
    {
        if(!mark[i])
        {
            primes.PSB(i);
            for(j=i*i;j<=1000;j+=2*i)mark[j]=1;
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     sieve();
    int i,n,k,l=primes.SZ-1,x,cnt=0;
    cin >> n >> k;
    for(i=0;i<l;i++)
    {
        x=primes[i]+primes[i+1]+1;
        if(x <= n  &&  !mark[x])++cnt;
    }
    if(cnt >= k)cout << "YES";
    else cout << "NO";
    return 0;
}