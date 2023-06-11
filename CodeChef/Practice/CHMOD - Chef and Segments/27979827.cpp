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
bool mark[101];
V<PII>prime_facts[101];
int n,idx[101],freq[100001][25];
void sieve()
{
    primes.PSB(2);
    int i,j,k;
    for(i=3;i<8;i+=2)
    {
        if(!mark[i])
        {
            primes.PSB(i);
            for(j=i*i,k=2*i;j<101;j+=k)mark[j]=1;
        }
    }
    for(i=11;i<98;i+=2)
    {
        if(!mark[i])primes.PSB(i);
    }
    for(i=0;i<25;i++)idx[primes[i]]=i;
}
void precal()
{
    int i,j,x,y,z;
    for(i=2;i<101;i++)
    {
        x=i;
        if(x%2 == 0)
        {
            y=2,z=0;
            while(x%2 == 0)x/=2,++z;
            prime_facts[i].PSB({y,z});
        }
        for(j=3;j<8;j+=2)
        {
            if(x%j == 0)
            {
                y=j,z=0;
                while(x%j == 0)x/=j,++z;
                prime_facts[i].PSB({y,z});
            }
        }
        if(x > 1)prime_facts[i].PSB({x,1});
    }
}
void make_the_freq_ara(int val,int cur)
{
    int i=0,j,x,y;
    for(j=0;j<25;j++)
    {
        x=primes[j];
        freq[cur][idx[x]]=freq[cur-1][idx[x]];
        if(i < prime_facts[val].SZ  &&  prime_facts[val][i].FI == x)freq[cur][idx[x]]+=prime_facts[val][i].SE,
    }
}
LL big_mod(LL val,LL pow,LL mod)
{
    LL res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sieve();
    precal();
    int i,l,r,q;
    LL x,y,mod,ans,temp;
    cin >> n;
    for(i=1;i<=n;i++)cin >> x,make_the_freq_ara(x,i);
    cin >> q;
    while(q--)
    {
        cin >> l >> r >> mod;
        ans=1;
        for(i=0;i<25;i++)
        {
            x=primes[i];
            y=freq[r][idx[x]]-freq[l-1][idx[x]];
            if(y > 0)
            {
                temp=big_mod(x,y,mod);
                ans=(ans*temp)%mod;
            }
        }
        cout << ans%mod << '\n';
    }
    return 0;
}