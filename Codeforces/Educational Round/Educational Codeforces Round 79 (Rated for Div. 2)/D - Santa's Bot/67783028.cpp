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
    LL cnt[1000002];
 LL mod_inverse(LL val,LL mod)
{
    LL mod1 = mod;
    if(mod == 1)return 0;
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
    if(x < 0)x += mod1;
    return x;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     LL i,j,k,n,x;
    const LL mod=998244353;
    cin >> n;
    V<LL>toys[n+2];
    for(i=1;i<=n;i++)
    {
        cin >> k;
        while(k--)
        {
            cin >> x;
            ++cnt[x];
            toys[i].PSB(x);
        }
    }
    LL ans=0LL,mdinvrs;
    for(i=1;i<=n;i++)
    {
        k=(LL)toys[i].SZ;
        mdinvrs=mod_inverse(n*n*k,mod)%mod;
        for(j=0;j<k;j++)ans+=(cnt[toys[i][j]]*mdinvrs)%mod,ans%=mod;
    }
    cout << (ans+mod)%mod;
    return 0;
}