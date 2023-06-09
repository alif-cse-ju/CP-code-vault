#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
    int i,t,cnt=1;
    scanf("%d",&t);
    scanf("%d",&a[0]);
    for(i=1; i<t; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] != a[i-1])
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;