#include<stdio.h>
#include<string.h>
int main()
    int l,j,cnt=0;
    char c[20];
    scanf("%s",&c);
    l=strlen(c);
    for(j=0; j<l/2; j++)
    {
        if(c[j]!=c[l-j-1])
        {
            cnt=cnt+1;
        }
    }
    if(cnt==1||(cnt==0&&l%2==1))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;