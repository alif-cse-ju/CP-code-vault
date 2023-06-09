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
   LL pre[200005];
 void preCal(int n,LL mod)
{
    pre[0]=1;
    for(int i=1;i<=n;i++)pre[i]=(pre[i-1]*i)%mod;
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
 LL inv(int x,LL mod)
{
    return big_mod(x,mod-2,mod);
}
 LL divide(int x,int y,LL mod)
{
    return (x*inv(y,mod))%mod;
}
 LL findAns(int n,int k,LL mod)
{
    return divide(pre[n],(pre[k]*pre[n-k])%mod,mod);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int m,n,ans=0;
    const LL mod=998244353;
    cin >> n >> m;
    preCal(m,mod);
    if(n > 2)ans=(findAns(m,n-1,mod)*(((n-2)*big_mod(2,n-3,mod))%mod))%mod;
    cout << ans;
    return 0;
}