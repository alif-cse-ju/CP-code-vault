#include<bits/stdc++.h>
using namespace std;
int main()
    long long int m,n,a,b,check1,check2;
    scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
    if(n%m == 0)
    {
        printf("0");
    }
    else
    {
        check1=(n%m)*b;
        check2=(((n/m)+1)*m-n)*a;
        if(check1 < check2)
        {
            printf("%lld",check1);
        }
        else
        {
            printf("%lld",check2);
        }
    }
    return 0;