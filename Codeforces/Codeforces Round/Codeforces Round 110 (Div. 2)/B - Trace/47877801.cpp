#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926536
int r[110];
int main()
    int i,n;
    double ans=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&r[i]);
    }
    sort(r+1,r+n+1);
    for(i=n; i>=1; i-=2)
    {
        ans+=PI*(r[i]*r[i] - r[i-1]*r[i-1]);
    }
    printf("%.10lf\n",ans);
    return 0;