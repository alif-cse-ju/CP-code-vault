#include<bits/stdc++.h>
using namespace std;
int main()
    int n,i,p,q,cnt=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d%d",&p,&q);
        if(q-p>=2)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;