#include<bits/stdc++.h>
using namespace std;
int a[10010];
void sieve()
    int i,j;
    a[0]=a[1]=1;
    for(i=4; i<=10007; i+=2)
    {
        a[i]=1;
    }
    for(i=3; i<=sqrt(10007); i+=2)
    {
        for(j=i*i; j<=10007; j+=2*i)
        {
            a[j]=1;
        }
    }
int main()
    sieve();
    long long int i,j,t,n,m;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("Case #%lld: 1\n",i);
        }
        else if(a[n]==0)
        {
            m=2;
            for(j=2;j<=n-1;j++)
            {
                m=(m*2)%n;
            }
            m=m%n;
            printf("Case #%lld: %lld\n",i,m);
        }
        else
        {
            m=(n-1)*(n-1);
            printf("Case #%lld: %lld\n",i,m%n);
        }
    }
    return 0;
}