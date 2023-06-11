#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,t,m,n,rx,ry,l,x,y;
    char c[10010];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        x=0,y=0;
        scanf("%d%d%d%d%d",&m,&n,&rx,&ry,&l);
        getchar();
        scanf("%s",&c);
        for(j=0;j<l;j++)
        {
            if(c[j]=='U')
            {
                y++;
            }
            else if(c[j]=='D')
            {
                y--;
            }
            else if(c[j]=='R')
            {
                x++;
            }
            else
            {
                x--;
            }
        }
        if(x==rx && y==ry)
        {
            printf("Case %d: REACHED\n",i);
        }
        else if(x<0 || x>m || y<0 || y>n)
        {
            printf("Case %d: DANGER\n",i);
        }
        else
        {
            printf("Case %d: SOMEWHERE\n",i);
        }
    }
    return 0;
}