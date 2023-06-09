#include<bits/stdc++.h>
using namespace std;
int main()
    int y,a[5],i,j;
    scanf("%d",&y);
    for(i=y+1; ; i++)
    {
        j=i;
        a[3]=j%10;
        j=j/10;
        a[2]=j%10;
        if(a[2]!=a[3])
        {
            j=j/10;
            a[1]=j%10;
            a[0]=j/10;
            if(a[1]!=a[2] && a[1]!=a[3])
            {
                if(a[0]!=a[1] && a[0]!=a[2] && a[0]!=a[3])
                {
                    printf("%d",i);
                    break;
                }
            }
        }
    }
    return 0;