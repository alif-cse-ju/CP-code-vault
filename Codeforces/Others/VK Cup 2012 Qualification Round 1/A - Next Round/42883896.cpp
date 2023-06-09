#include<bits/stdc++.h>
using namespace std;
int main()
    int n,k,i,cnt=0;
    scanf("%d%d",&n,&k);
    int a[n+10];
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<=n; i++)
    {
        if(a[i]>=a[k]&&a[i]>0)
        {
            cnt++;
        }
        else if(a[i]<a[k])
        {
            break;
        }
    }
    printf("%d",cnt);
    return 0;