#include<bits/stdc++.h>
using namespace std;
int digitsum(int i)
    int sum=0;
    while(i>0)
    {
        sum+=i%10;
        i/=10;
    }
    return sum;
int main()
    long long int k,i,cnt=0;
    scanf("%lld",&k);
    for(i=19; ;i+=9)
    {
        if(digitsum(i)==10)
        {
            cnt++;
            if(cnt==k)
            {
                printf("%lld",i);
                break;
            }
        }
    }
    return 0;