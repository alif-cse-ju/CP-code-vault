#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define C clear()
#define B begin()
#define E end()
#define V vector
#define Fi first
#define Se second
#define PI acos(-1)
#define PS push
#define PP pop
#define PSB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
void FAST();
LL big_mod(LL val,LL pow,LL mod);
int main()
//    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n,m,h,x,y,z;
    S("%d %d %d",&n,&h,&m);
    int ans[55];
    for(i=1; i<=n; i++)
    {
        ans[i]=h;
    }
    for(i=1; i<=m; i++)
    {
        S("%d %d %d",&x,&y,&z);
        for(j=x; j<=y; j++)
        {
            if(ans[j] > z)
            {
                ans[j]=z;
            }
        }
    }
    int cnt=0;
    for(i=1; i<=n; i++)
    {
        cnt+=(ans[i]*ans[i]);
    }
    P("%d",cnt);
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