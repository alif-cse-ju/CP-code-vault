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
       int a[110],b[110],ans[110][110];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,check,ans=INT_MAX;
    string s;
    cin >> n >> s;
    for(i=0;i<n-3;i++)
    {
        check=min(s[i]-65,91-s[i]);
        if(s[i+1] > 'C')
        {
            check+=min(s[i+1]-'C','Z'-s[i+1]+3);
        }
        else
        {
            check+='C'-s[i+1];
        }
        if(s[i+2] > 'T')
        {
            check+=min(s[i+2]-'T','Z'-s[i+2]+'T'-64);
        }
        else
        {
            check+=min('T'-s[i+2],s[i+2]-64+'Z'-'T');
        }
        if(s[i+3] > 'G')
        {
            check+=min(s[i+3]-'G','Z'-s[i+3]+7);
        }
        else
        {
            check+='G'-s[i+3];
        }
        ans=min(ans,check);
    }
    cout << ans;
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