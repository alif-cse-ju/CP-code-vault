#include<bits/stdc++.h>
using namespace std;
int main()
    int n,i,a,b,c,cnt1=0,cnt2=0,cnt3=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        cnt1=cnt1+a;
        cnt2=cnt2+b;
        cnt3=cnt3+c;
    }
    if(cnt1==0 && cnt2==0 && cnt3==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;