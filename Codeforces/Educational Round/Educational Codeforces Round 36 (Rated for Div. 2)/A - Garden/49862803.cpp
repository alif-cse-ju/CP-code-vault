#include<bits/stdc++.h>
using namespace std;
int main()
    int i,n,k,a[110];
    scanf("%d %d",&n,&k);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=n-1; i>=0; i--)
    {
        if(k%a[i] == 0)
        {
            printf("%d",k/a[i]);
            break;
        }
    }
    return 0;