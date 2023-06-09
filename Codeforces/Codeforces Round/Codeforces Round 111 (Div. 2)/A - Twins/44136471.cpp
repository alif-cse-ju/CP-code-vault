#include<bits/stdc++.h>
using namespace std;
int main()
    int n,i,a[110],cnt=0,sum1=0,sum2=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        sum1=sum1+a[i];
    }
    sort(a,a+n);
    for(i=n-1; i>=0; i--)
    {
        sum1=sum1-a[i];
        sum2=sum2+a[i];
        cnt++;
        if(sum2>sum1)
        {
            break;
        }
    }
    printf("%d",cnt);
    return 0;