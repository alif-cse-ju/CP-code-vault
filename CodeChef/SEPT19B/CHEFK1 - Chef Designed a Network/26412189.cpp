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
//    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    int t;
    LL n,m,ans;
    S("%d",&t);
    while(t--)
    {
        S("%lld %lld",&n,&m);
        if(n == 1)
        {
            if(m <= 1)
            {
                P("%lld\n",m);
            }
            else
            {
                P("-1\n");
            }
        }
        else if(n == 2  &&  m == 1)
        {
            P("1\n");
        }
        else
        {
            if((m > (n*(n-1))/2+n)  ||  (m < n-1))
            {
                P("-1\n");
            }
            else if(m <= n+1)
            {
                P("2\n");
            }
            else
            {
                m-=(2*n);
                if(m <= 0)
                {
                    P("3\n");
                }
                else
                {
                    ans=3;
                    ans+=(m/n*2);
                    m%=n;
                    if(m > 0)
                    {
                        if(m <= n/2)
                        {
                            ans++;
                        }
                        else
                        {
                            ans+=2;
                        }
                    }
                    P("%lld\n",ans);
                }
            }
        }
    }
    return 0;
}