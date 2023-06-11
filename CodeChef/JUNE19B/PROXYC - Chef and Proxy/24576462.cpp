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
#define FAST() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
LL big_mod(LL val,LL pow,LL mod);
LL mod_inverse(LL val,LL mod);
ST<int>for_cnt;
int main()
{
//    FAST();
//
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    const double range=0.7500;
    int i,t;
    char s[1002];
    double n,prsnt_cnt,prx_cnt;
    S("%d",&t);
    while(t--)
    {
        S("%lf %s",&n,s);
        prsnt_cnt=prx_cnt=0;
        for(i=0;i<int(n);i++)
        {
            if(s[i] == 'P')
            {
                prsnt_cnt++;
            }
            else if(i>1  &&  i<n-2  &&  (s[i-1] == 'P'  ||  s[i-2] == 'P')  &&  (s[i+1] == 'P'  ||  s[i+2] == 
            {
                prx_cnt++;
            }
        }
        if((prsnt_cnt/n) >= range)
        {
            P("0\n");
        }
        else if(((prsnt_cnt+prx_cnt)/n) < range)
        {
            P("-1\n");
        }
        else
        {
            P("%.0lf\n",ceil((range*n)-prsnt_cnt));
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