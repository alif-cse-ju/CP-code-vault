#include<stdio.h>
int main()
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n],i,j,k,cnt=0;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<=n; i++)
    {
        for(j=n; j>=i; j--)
        {
            if(a[j]<a[i])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    for(i=1; i<=m; i++)
    {
        if(a[i]>0)
        {
            a[i]=0;
        }
        cnt=(cnt+a[i]);
    }
    printf("%d",cnt*(-1));
    return 0;