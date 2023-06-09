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
 V<int>divs;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,a[5];
    for(i=0; i<3; i++)
    {
        S("%d",&a[i]);
    }
    sort(a,a+3);
    int l1,l2=0,l3=0;
    l1=__gcd(a[0],a[1]);
    for(i=1; i<=sqrt(l1); i++)
    {
        if(l1%i == 0)
        {
            divs.PSB(i);
            divs.PSB(l1/i);
        }
    }
    sort(divs.B,divs.E);
    i=divs.size()-1;
    l2=a[0]/l1;
    l3=a[1]/l1;
    while(l2*l3 != a[2] && i>=0)
    {
        i--;
        l1=divs[i];
        l2=a[0]/l1;
        l3=a[1]/l1;
    }
    P("%d",4*(l1+l2+l3));
    return 0;