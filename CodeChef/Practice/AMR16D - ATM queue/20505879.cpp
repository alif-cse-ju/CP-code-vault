#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,t,n,k;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d",&n,&k);
        if(k%3==0)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
    return 0;
}