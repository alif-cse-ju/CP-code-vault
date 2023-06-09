#include<bits/stdc++.h>
using namespace std;
int main()
    int n,l,i,cnt=0;
    char c[60];
    scanf("%d",&n);
    getchar();
    scanf("%s",&c);
    l=strlen(c);
    for(i=0; i<l-1; i++)
    {
        if(c[i]==c[i+1])
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;