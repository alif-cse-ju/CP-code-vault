#include<bits/stdc++.h>
using namespace std;
int main()
    int i,l,x=0;
    char c[110],d[110];
    scanf("%s%s",&c,&d);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        if(c[i]>='A'&&c[i]<='Z')
        {
            c[i]=c[i]+32;
        }
        if(d[i]>='A'&&d[i]<='Z')
        {
            d[i]=d[i]+32;
        }
        if(c[i]>d[i])
        {
            x=1;
            break;
        }
        if(c[i]<d[i])
        {
            x=-1;
            break;
        }
    }
    printf("%d",x);
    return 0;