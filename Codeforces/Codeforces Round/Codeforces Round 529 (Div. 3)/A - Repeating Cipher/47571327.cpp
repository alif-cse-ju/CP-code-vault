#include<bits/stdc++.h>
using namespace std;
int main()
    int i,n,ans=1;
    char c[60];
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%c",&c[i]);
    }
    for(i=1;ans<=n;i++)
    {
        printf("%c",c[ans]);
        ans+=i;
    }
    return 0;