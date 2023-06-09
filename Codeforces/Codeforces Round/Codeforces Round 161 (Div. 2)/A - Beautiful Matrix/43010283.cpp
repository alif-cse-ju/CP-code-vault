#include<bits/stdc++.h>
using namespace std;
int main()
    int i,x,row,clm,cnt;
    int a[30];
    for(i=0; i<25; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
        {
            x=i;
        }
    }
    row=x/5+1;
    clm=x%5+1;
    cnt=fabs(row-3)+fabs(clm-3);
    printf("%d",cnt);
    return 0;