#include<bits/stdc++.h>
using namespace std;
int main()
    int n,i,x=0;
    scanf("%d",&n);
    getchar();
    char c[10];
    for(i=1; i<=n; i++)
    {
        scanf("%s",&c);
        if(c[0]=='-'||c[2]=='-')
        {
            x=x-1;
        }
        else
        {
            x++;
        }
    }
    printf("%d",x);
    return 0;