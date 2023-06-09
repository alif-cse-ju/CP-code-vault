#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int main()
    scanf("%d %d",&n,&m);
    if(n >= m)
    {
        printf("%d",n-m);
    }
    else
    {
        while(n < m)
        {
            if(m%2 == 1)
            {
                m++;
                cnt++;
            }
            m/=2;
            cnt++;
        }
        printf("%d",cnt+n-m);
    }
    return 0;