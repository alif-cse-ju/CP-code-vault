#include<bits/stdc++.h>
using namespace std;
int main()
    long long int x;
    scanf("%lld",&x);
    if(x%5==0)
    {
        printf("%lld",x/5);
    }
    else
    {
        printf("%lld",(x/5)+1);
    }
    return 0;