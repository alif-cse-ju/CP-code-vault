#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,t,a,b,x,y,check,cnt,ans;
    char c[10],d[10];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        cnt=0;
        scanf("%s %s %d %d",&c,&d,&a,&b);
        getchar();
        if(strcmp(c,"saturday") == 0)
        {
            x=1;
        }
        else if(strcmp(c,"sunday") == 0)
        {
            x=2;
        }
        else if(strcmp(c,"monday") == 0)
        {
            x=3;
        }
        else if(strcmp(c,"tuesday") == 0)
        {
            x=4;
        }
        else if(strcmp(c,"wednesday") == 0)
        {
            x=5;
        }
        else if(strcmp(c,"thursday") == 0)
        {
            x=6;
        }
        else if(strcmp(c,"friday") == 0)
        {
            x=7;
        }
        if(strcmp(d,"saturday") == 0)
        {
            y=1;
        }
        else if(strcmp(d,"sunday") == 0)
        {
            y=2;
        }
        else if(strcmp(d,"monday") == 0)
        {
            y=3;
        }
        else if(strcmp(d,"tuesday") == 0)
        {
            y=4;
        }
        else if(strcmp(d,"wednesday") == 0)
        {
            y=5;
        }
        else if(strcmp(d,"thursday") == 0)
        {
            y=6;
        }
        else if(strcmp(d,"friday") == 0)
        {
            y=7;
        }
        check=y-x+1;
        while(check<=b)
        {
            if(check>=a)
            {
                cnt++;
                if(cnt == 1)
                {
                    ans=check;
                }
            }
            check+=7;
        }
        if(cnt == 1)
        {
            printf("%d\n",ans);
        }
        else if(cnt == 0)
        {
            printf("impossible\n");
        }
        else
        {
            printf("many\n");
        }
    }
    return 0;
}