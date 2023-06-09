#include<bits/stdc++.h>
using namespace std;
int main()
    int i,la,lb,t,pos,cur,ans;
    char a[100002],b[100002];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",a+1,b+1);
        la=strlen(a+1);
        lb=strlen(b+1);
        pos=la,cur=lb,ans=0;
        while(b[cur] == '0')--cur,--pos;
        while(a[pos] == '0')--pos,++ans;
        printf("%d\n",ans);
    }
    return 0;