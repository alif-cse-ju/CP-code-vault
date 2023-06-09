#include<bits/stdc++.h>
using namespace std;
int num[5010];
int main()
    int i,n,x,cnt=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        num[x]++;
    }
    for(i=1; i<=n; i++)
    {
        if(num[i] == 0)
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;