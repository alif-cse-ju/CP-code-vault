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
MII mp;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a[100010],i,n;
    S("%d",&n);
    for(i=1;i<=n;i++)
    {
        S("%d",&a[i]);
        mp[a[i]]++;
    }
    int check=INT_MAX,ans=0;
    for(i=1;i<=n;i++)
    {
        if(a[i] < check)
        {
            check=a[i];
            ans=i;
        }
    }
    if(mp[check] == 1)
    {
        P("%d",ans);
    }
    else
    {
        P("Still Rozdil");
    }
    return 0;
}