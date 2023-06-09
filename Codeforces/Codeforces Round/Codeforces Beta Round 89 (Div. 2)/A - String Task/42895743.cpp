#include<bits/stdc++.h>
using namespace std;
int main()
    char c[110];
    gets(c);
    int l,i;
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        if((c[i]>=65)&&(c[i]<=90))
        {
            c[i]=c[i]+32;
        }
        if((c[i]=='a')||(c[i]=='e')||(c[i]=='i')||(c[i]=='o')||(c[i]=='u')||(c[i]=='y'))
        {
            continue;
        }
        else
        {
            printf(".%c",c[i]);
        }
    }
    return 0;