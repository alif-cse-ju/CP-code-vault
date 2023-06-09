#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;