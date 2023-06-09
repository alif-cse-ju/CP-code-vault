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
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
int a[10];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int cnt=0,ans=0;
    int i,n;
    S("%d",&n);
    for(i=0;i<7;i++)
    {
        S("%d",&a[i]);
    }
    i=0;
    while(cnt < n)
    {
        cnt+=a[i%7];
        i++;
        ans++;
        //cout << cnt << ' ' << ans << endl;
    }
    if(ans%7 == 0)
    {
        cout << 7;
        return 0;
    }
    cout << ans%7;
    return 0;
}