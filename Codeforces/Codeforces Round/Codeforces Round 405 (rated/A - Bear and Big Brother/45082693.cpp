#include<bits/stdc++.h>
using namespace std;
int main()
    int a,b,cnt=0;
    scanf("%d %d",&a,&b);
    if(a == b)
    {
        printf("1\n");
    }
    else
    {
        while(a<=b)
        {
            cnt++;
            a=a+a+a;
            b=b+b;
        }
        printf("%d\n",cnt);
    }
    return 0;