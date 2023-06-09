#include<bits/stdc++.h>
using namespace std;
int main()
    long long int n,i,a,b,cnt=1,max=1;
    scanf("%lld",&n);
    scanf("%lld",&b);
    for(i=2; i<=n; i++)
    {
        scanf("%lld",&a);
        if(a>=b)
        {
            cnt++;
            if(i==n)
            {
                if(cnt>max)
                {
                    max=cnt;
                }
            }
        }
        else
        {
            if(cnt>max)
            {
                max=cnt;
            }
            cnt=1;
        }
        b=a;
    }
    printf("%lld",max);
    return 0;