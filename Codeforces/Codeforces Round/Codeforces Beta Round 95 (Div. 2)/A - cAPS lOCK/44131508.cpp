#include<bits/stdc++.h>
using namespace std;
int main()
    char c[110];
    int i,l,cnt=0;
    scanf("%s",&c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        if(c[i]>='A'&&c[i]<='Z')
        {
            cnt++;
        }
    }
    if(cnt<l-1)
    {
        printf("%s",c);
    }
    else
    {
        if(cnt==l)
        {
            for(i=0; i<l; i++)
            {
                printf("%c",c[i]+32);
            }
        }
        else
        {
            if(c[0]>='A'&&c[0]<='Z')
            {
                printf("%s",c);
            }
            else
            {
                printf("%c",c[0]-32);
                for(i=1; i<l; i++)
                {
                    printf("%c",c[i]+32);
                }
            }
        }
    }
     return 0;
}