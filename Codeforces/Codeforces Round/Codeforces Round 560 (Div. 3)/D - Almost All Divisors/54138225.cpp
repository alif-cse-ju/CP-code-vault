#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define Si size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define Em empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define Fi first
#define Se second
#define Pi acos(-1)
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
#define FAST() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 LL big_mod(LL val,LL pow,LL mod);
LL mod_inverse(LL val,LL mod);
       LL a[310];
 int main()
{
//    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,t,n;
    LL ans;
    S("%d",&t);
    while(t--)
    {
        S("%d",&n);
        for(i=1;i<=n;i++)
        {
            S("%lld",&a[i]);
        }
        sort(a+1,a+n+1);
        ans=a[1]*a[n];
        bool flag=1;
        for(i=2;i<=n/2;i++)
        {
            if((a[i]*a[n-i+1]) != ans)
            {
                flag=0;
                P("-1\n");
                break;
            }
        }
        if(n & 1   &&    flag == 1)
        {
            if(a[n/2+1]*a[n/2+1] != ans)
            {
                flag=0;
                P("-1\n");
            }
        }
        if(flag == 1)
        {
            int cnt=0;
            for(i=2;i<=sqrt(ans);i++)
            {
                if(ans%i == 0)
                {
                    cnt+=2;
                }
            }
            if(sqrt(ans)*sqrt(ans) == ans)
            {
                cnt--;
            }
            if(cnt != n)
            {
                flag=0;
                P("-1\n");
            }
        }
        if(flag == 1)
        {
            P("%lld\n",ans);
        }
    }
    return 0;
}
       LL big_mod(LL val,LL pow,LL mod)
{
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)
        {
            res = (res*val) % mod;
        }
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
 LL mod_inverse(LL val,LL mod)
{
    LL mod1 = mod;
    if(mod == 1)
    {
        return 0;
    }
    LL y = 0;
    LL x = 1;
    LL quotient,temp;
    while(val > 1)
    {
        quotient = val / mod;
        temp = mod;
        mod = val % mod;
        val = temp;
        temp = y;
        y = x - quotient * y;
        x = temp;
    }
    if(x < 0)
    {
        x += mod1;
    }
    return x;
}