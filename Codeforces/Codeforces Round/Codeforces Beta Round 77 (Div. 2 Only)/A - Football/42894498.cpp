#include<stdio.h>
#include<string.h>
int main()
    int cnt0=0,cnt1=0,l,i;
    char a[120];
    gets(a);
    l=strlen(a);
    for(i=0; i<l; i++)
    {
        if(a[i]=='0')
        {
            cnt0=cnt0+1;
            cnt1=0;
        }
        else
        {
            cnt1=cnt1+1;
            cnt0=0;
        }
        if(cnt0==7||cnt1==7)
        {
            printf("YES");
            break;
        }
        else if(i==(l-1))
        {
            printf("NO");
        }
    }
    return 0;