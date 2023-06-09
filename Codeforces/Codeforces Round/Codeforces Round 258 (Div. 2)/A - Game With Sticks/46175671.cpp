#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
    int m,n;
    scanf("%d %d",&m,&n);
    if(m == 1  ||  n == 1)
    {
        printf("Akshat\n");
    }
    else
    {
        if(m>n)
        {
            m=m^n;
            n=m^n;
            m=m^n;
        }
        if(m%2 == 0)
        {
            printf("Malvika\n");
        }
        else
        {
            printf("Akshat\n");
        }
    }
    return 0;