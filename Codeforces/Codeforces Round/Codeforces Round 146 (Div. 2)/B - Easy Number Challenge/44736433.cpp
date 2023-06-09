#include<bits/stdc++.h>
using namespace std;
int divisors[1000010];
void div(int range)
    int i,j;
    for(i=1; i<=range; i++)
    {
        for(j=i; j<=range; j+=i)
        {
            divisors[j]++;
        }
    }
int main()
    int a,b,c,i,j,k,ans=0,range;
    scanf("%d%d%d",&a,&b,&c);
    range=a*b*c;
    div(range);
    for(i=1; i<=a; i++)
    {
        for(j=1; j<=b; j++)
        {
            for(k=1; k<=c; k++)
            {
                ans+=divisors[i*j*k];
            }
        }
    }
    printf("%d\n",ans%1073741824);
    return 0;