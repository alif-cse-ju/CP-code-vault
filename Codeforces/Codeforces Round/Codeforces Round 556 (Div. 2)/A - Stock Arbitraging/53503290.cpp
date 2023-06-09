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
int a[35],b[35];
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,m,r;
    scanf("%d %d %d",&n,&m,&r);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<=m; i++)
    {
        scanf("%d",&b[i]);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    if(a[1] > b[m])
    {
        cout << r ;
    }
    else
    {
        int ans;
        int cnt=(r/a[1]);
        ans=r-cnt*a[1];
        ans+=cnt*b[m];
        cout << ans;
    }
    return 0;
}