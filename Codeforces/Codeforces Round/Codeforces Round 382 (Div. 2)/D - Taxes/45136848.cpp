#include<bits/stdc++.h>
using namespace std;
int minburles(long long int n)
    long long int i;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
int main()
    long long int n;
    scanf("%lld",&n);
    if( n == 2 )
    {
        printf("1\n");
    }
    else if( n%2 == 0 )
    {
        printf("2\n");
    }
    else
    {
        if( minburles(n) == 1 )
        {
            printf("1\n");
        }
        else if( minburles(n-2) == 1 )
        {
            printf("2\n");
        }
        else
        {
            printf("3\n");
        }
    }
    return 0;
}