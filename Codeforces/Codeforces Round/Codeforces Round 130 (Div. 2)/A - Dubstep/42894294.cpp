#include<bits/stdc++.h>
using namespace std;
int main()
    char c[210];
    scanf("%s",&c);
    int l,i;
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        if(c[i]=='W'&&c[i+1]=='U'&&c[i+2]=='B')
        {
            i=i+2;
        }
        else
        {
            printf("%c",c[i]);
            if(c[i+1]=='W'&&c[i+2]=='U'&&c[i+3]=='B')
            {
                printf(" ");
            }
        }
    }
    return 0;