#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
    int i,n,check;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    if(n == 2)
    {
        printf("0\n");
    }
    else
    {
        check=a[n-2]-a[0];
        if(check<=(a[n-1]-a[1]))
        {
            printf("%d\n",check);
        }
        else
        {
            printf("%d",a[n-1]-a[1]);
        }
    }
    return 0;