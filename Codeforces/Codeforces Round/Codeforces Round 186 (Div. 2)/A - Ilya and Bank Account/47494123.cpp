#include<bits/stdc++.h>
using namespace std;
long long int n;
char c[100];
int main()
    int i,l;
    scanf("%s",&c);
    l=strlen(c);
    if(c[0]>='1' && c[0]<='9')
    {
        printf("%s",c);
    }
    else
    {
        if(l == 3 && c[2] == '0')
        {
            printf("0");
        }
        else
        {
            if(c[l-2]<=c[l-1])
            {
                for(i=0; i<l-1; i++)
                {
                    printf("%c",c[i]);
                }
            }
            else
            {
                for(i=0; i<l-2; i++)
                {
                    printf("%c",c[i]);
                }
                printf("%c",c[l-1]);
            }
        }
    }
    return 0;
}