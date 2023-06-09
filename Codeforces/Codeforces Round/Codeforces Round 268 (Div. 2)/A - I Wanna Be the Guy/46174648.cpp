#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
    int n,x,y,i;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    scanf("%d",&x);
    for(i=1; i<=x; i++)
    {
        scanf("%d",&y);
        a[y]=1;
    }
    scanf("%d",&x);
    for(i=1; i<=x; i++)
    {
        scanf("%d",&y);
        a[y]=1;
    }
    int flag=0;
    for(i=1; i<=n; i++)
    {
        if(a[i] == 0)
        {
            flag=1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Oh, my keyboard!\n");
    }
    else
    {
        printf("I become the guy.\n");
    }
    return 0;
}