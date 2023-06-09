#include<stdio.h>
#include<string.h>
int main()
    char d[1200];
    scanf("%s",&d);
    if(d[0]>='a'&&d[0]<='z')
    {
        d[0]=d[0]-32;
    }
    printf("%s",d);
    return 0;