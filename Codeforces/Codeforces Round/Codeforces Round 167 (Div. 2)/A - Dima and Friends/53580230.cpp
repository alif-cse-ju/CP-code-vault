#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define PB push_back
#define LL long long int
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,x,cnt=0,ans=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        cnt+=x;
    }
    n++;
    for(i=1;i<=5;i++)
    {
        if((cnt+i)%n == 1)
        {
            ans++;
        }
    }
    cout << 5-ans << endl;
    return 0;
}