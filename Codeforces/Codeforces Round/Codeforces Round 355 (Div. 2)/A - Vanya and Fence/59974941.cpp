#include<bits/stdc++.h>
using namespace std;
int main()
    int n,h,x,ans;
    scanf("%d %d",&n,&h);
    ans=n;
    while(n--)
    {
        scanf("%d",&x);
        if(x > h)
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;