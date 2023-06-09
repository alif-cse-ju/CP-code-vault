#include<bits/stdc++.h>
using namespace std;
int main()
    int a1,b1,c1,a2,b2,c2,total=0;
    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
    if(a2>a1)
    {
        total=total+a2-a1;
    }
    if(b2>b1)
    {
        total=total+b2-b1;
    }
    if(c2>c1)
    {
        total=total+c2-c1;
    }
    printf("%d",total);
    return 0;