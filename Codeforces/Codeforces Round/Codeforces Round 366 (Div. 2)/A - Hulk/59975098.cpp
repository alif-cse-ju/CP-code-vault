#include<bits/stdc++.h>
using namespace std;
int main()
    int i,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        if(i & 1)
        {
            printf("I hate ");
        }
        else
        {
            printf("I love ");
        }
        if(i < n)
        {
            printf("that ");
        }
        else
        {
            printf("it");
        }
    }
    return 0;