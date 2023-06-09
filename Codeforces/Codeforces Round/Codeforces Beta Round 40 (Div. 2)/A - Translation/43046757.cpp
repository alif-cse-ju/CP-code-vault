#include<bits/stdc++.h>
using namespace std;
int main()
    char a[110],b[110];
    int l1,l2,i,flag=1;
    scanf("%s",a);
    scanf("%s",b);
    l1=strlen(a);
    l2=strlen(b);
    if(l1!=l2)
    {
        printf("NO");
    }
    else
    {
        for(i=0; i<l1; i++)
        {
            if(a[i]!=b[l1-i-1])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    return 0;