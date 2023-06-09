#include<bits/stdc++.h>
using namespace std;
int main()
    long long int i,m,n,a[200010],extra;
    scanf("%lld %lld",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }
    extra=a[0]%m;
    printf("%lld ",a[0]/m);
    for(i=1; i<n; i++)
    {
        a[i]=a[i]+extra;
        printf("%lld ",a[i]/m);
        extra=a[i]%m;
    }
    return 0;