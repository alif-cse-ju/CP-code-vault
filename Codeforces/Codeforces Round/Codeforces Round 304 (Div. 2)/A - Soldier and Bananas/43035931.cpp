#include<bits/stdc++.h>
using namespace std;
int main()
    long long int k,n,w,cnt=0,i;
    scanf("%lld%lld%lld",&k,&n,&w);
    for(i=1; i<=w; i++)
    {
        cnt=cnt+i*k;
    }
    if(cnt>n)
    {
        printf("%lld",cnt-n);
    }
    else
    {
        printf("0");
    }
    return 0;