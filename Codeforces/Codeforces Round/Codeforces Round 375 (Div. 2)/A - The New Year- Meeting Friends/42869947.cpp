#include<bits/stdc++.h>
using namespace std;
int main()
    int a[5],i,n=3;
    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    printf("%d",a[2]-a[0]);
    return 0;