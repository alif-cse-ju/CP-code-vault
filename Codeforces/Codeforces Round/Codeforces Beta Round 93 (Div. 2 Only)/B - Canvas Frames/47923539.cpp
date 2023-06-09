#include<bits/stdc++.h>
using namespace std;
int mark[110];
int main()
    int n,i,x,cnt=0;
    bool flag=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        mark[x]++;
    }
    for(i=1; i<=100; i++)
    {
        if(mark[i]>=4)
        {
            cnt+=mark[i]/4;
            mark[i]=mark[i]%4;
        }
        if(mark[i]>=2)
        {
            if(flag == 1)
            {
                cnt++;
                flag=0;
            }
            else
            {
                flag=1;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;