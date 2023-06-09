#include<bits/stdc++.h>
using namespace std;
int main()
    int l,i,flag=0;
    char c[110];
    scanf("%s",&c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        if(c[i]=='H'||c[i]=='Q'||c[i]=='9')
        {
            flag=1;
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
    return 0;