#include<bits/stdc++.h>
using namespace std;
int main()
    int t,a,b,c,i,cnt=0;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a+b+c>=2)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;