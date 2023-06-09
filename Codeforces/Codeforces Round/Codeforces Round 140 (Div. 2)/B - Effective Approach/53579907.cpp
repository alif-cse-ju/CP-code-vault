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
struct Data
    int a;
    int b;
Data check[100010];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,q,x;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        check[x].a=i;
        check[x].b=n-i+1;
    }
    cin >> q;
    long long int cnt1=0,cnt2=0;
    while(q--)
    {
        cin >> x;
        cnt1+=check[x].a;
        cnt2+=check[x].b;
    }
    cout << cnt1 << ' ' << cnt2 << '\n';
    return 0;
}