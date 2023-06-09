#include<bits/stdc++.h>
using namespace std;
int main()
    char c[25];
    int i,l,cnt=0;
    scanf("%s",c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        if(c[i]=='4' || c[i]=='7')
        {
            cnt++;
        }
    }
    if(cnt==4 || cnt==7)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;