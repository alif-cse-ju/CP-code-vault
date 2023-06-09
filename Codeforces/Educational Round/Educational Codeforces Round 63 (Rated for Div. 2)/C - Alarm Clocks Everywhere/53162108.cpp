#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
long long int tim[300010];
long long int pulse[300010];
vector<long long int>v;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,m;
    scanf("%d %d",&n,&m);
    scanf("%lld",&tim[1]);
    for(i=2; i<=n; i++)
    {
        scanf("%lld",&tim[i]);
        v.push_back(tim[i]-tim[i-1]);
    }
    for(i=1; i<=m; i++)
    {
        scanf("%lld",&pulse[i]);
    }
    long long int ans=v[0];
    for(i=1; i<n-1; i++)
    {
        ans=__gcd(ans,v[i]);
    }
    for(i=1;i<=m;i++)
    {
        if(ans%pulse[i] == 0)
        {
            printf("YES\n%lld %d",tim[1],i);
            return 0;
        }
    }
    printf("NO");
    return 0;
}