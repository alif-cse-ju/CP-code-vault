#include<bits/stdc++.h>
using namespace std;
int main()
    long long int n,s;
    scanf("%lld %lld",&n,&s);
    if(s%n == 0)
    {
        printf("%lld\n",s/n);
    }
    else
    {
        printf("%lld\n",s/n+1);
    }
    return 0;