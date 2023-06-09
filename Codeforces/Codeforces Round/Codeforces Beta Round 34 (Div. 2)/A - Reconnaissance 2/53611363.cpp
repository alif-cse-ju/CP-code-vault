#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
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
int a[105];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,dif,check;
    PII p;
    S("%d",&n);
    for(i=1;i<=n;i++)
    {
        S("%d",&a[i]);
    }
    dif=abs(a[n]-a[1]);
    p.Fi=n;
    p.Se=1;
    for(i=2;i<=n;i++)
    {
        check=abs(a[i]-a[i-1]);
        if(check < dif)
        {
            dif=check;
            p.Fi=i-1;
            p.Se=i;
        }
    }
    P("%d %d",p.Fi,p.Se);
    return 0;
}