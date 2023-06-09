#include<bits/stdc++.h>
using namespace std;
int main()
    char c[105];
    int t,i,l;
    scanf("%d",&t);
    getchar();
    for(i=1; i<=t; i++)
    {
        scanf("%s",&c);
        l=strlen(c);
        if(l>10)
        {
            printf("%c%d%c",c[0],l-2,c[l-1]);
        }
        else
        {
            printf("%s",c);
        }
        if(i<t)
        {
            printf("\n");
        }
    }
    return 0;