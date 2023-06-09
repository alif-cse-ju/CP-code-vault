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
   V<int>primes;
bool mark[45];
 void sieve()
{
    int i,j;
    primes.emplace_back(2);
    for(i=3;i<33;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i;j<40;j+=i)mark[j]=1;
        }
    }
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     sieve();
    bool flag;
    int i,j,n,t,x,cnt,a[1005],ans[1005];
    cin >> t;
    while(t--)
    {
        cnt=0;
        cin >> n;
        for(i=0;i<n;i++)cin >> a[i],ans[i]=0;
        for(i=0;i<11;i++)
        {
            x=primes[i];
            flag=false;
            for(j=0;j<n;j++)
            {
                if(ans[j] == 0)
                {
                    if(a[j]%x == 0)
                    {
                        if(!flag)++cnt,flag=true;
                        ans[j]=cnt;
                    }
                }
            }
        }
        cout << cnt << '\n';
        for(i=0;i<n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}