#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define C clear()
#define B begin()
#define E end()
#define V vector
#define Q queue
#define PQ priority_queue
#define ST stack
#define Fi first
#define Se second
#define PI acos(-1)
#define PS push
#define PP pop
#define PSB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
void FAST();
LL big_mod(LL val,LL pow,LL mod);
LL ans[1000010];
void make_the_ans()
{
    ans[1]=1;
    ans[2]=5;
    LL i,mod=1000000007;
    for(i=3;i<=1000000;i++)
    {
        ans[i]=(ans[i-1]+i+(ans[i-1]*i)%mod)%mod;
    }
}
int main()
{
//    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    make_the_ans();
    int t,n;
    S("%d",&t);
    while(t--)
    {
        S("%d",&n);
        P("%lld\n",ans[n]);
    }
    return 0;
}
void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
LL big_mod(LL val,LL pow,LL mod)
{
    LL res=1;
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