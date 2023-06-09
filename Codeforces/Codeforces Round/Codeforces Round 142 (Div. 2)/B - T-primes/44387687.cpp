#include<bits/stdc++.h>
using namespace std;
int a[1000010];
void sieve()
    long long int i,j;
    a[0]=a[1]=1;
    for(i=4; i<=1000000; i+=2)
    {
        a[i]=1;
    }
    for(i=3; i<=sqrt(1000000); i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=1000000; j+=2*i)
            {
                a[j]=1;
            }
        }
    }
int rootcheck(long long int n)
    long long int rooti=sqrt(n);
    double rootd=sqrt(n);
    if(rooti==rootd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
 int main()
{
    sieve();
    long long int i,t,n,root;
    cin >> t;
    for(i=1; i<=t; i++)
    {
        cin >> n;
        if(n==4)
        {
            printf("YES\n");
        }
        else if(n<2 || n%2==0)
        {
            printf("NO\n");
        }
        else
        {
            root=sqrt(n);
            if(rootcheck(n)==1 && a[root]==0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}