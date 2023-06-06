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








int main()
{
//    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,a[5];
    cin >> n;
    if(n <= 111)
    {
        P("111");
    }
    else if(n <= 222)
    {
        P("222");
    }
    else if(n <= 333)
    {
        P("333");
    }
    else if(n <= 444)
    {
        P("444");
    }
    else if(n <= 555)
    {
        P("555");
    }
    else if(n <= 666)
    {
        P("666");
    }
    else if(n <= 777)
    {
        P("777");
    }
    else if(n <= 888)
    {
        P("888");
    }
    else
    {
        P("999");
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
