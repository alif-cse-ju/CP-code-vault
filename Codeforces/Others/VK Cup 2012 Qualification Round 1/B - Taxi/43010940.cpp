#include<bits/stdc++.h>
using namespace std;
int main()
    long long int n,i,cnt1=0,cnt2=0,cnt3=0,cnt4=0,total;
    scanf("%lld",&n);
    int a;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            cnt1++;
        }
        else if(a==2)
        {
            cnt2++;
        }
        else if(a==3)
        {
            cnt3++;
        }
        else
        {
            cnt4++;
        }
    }
    total=cnt4+cnt3+cnt2/2;
    if(cnt1>cnt3)
    {
        cnt1=cnt1-cnt3;
    }
    else
    {
        cnt1=0;
    }
    if(cnt2%2==1)
    {
        total++;
        cnt1=cnt1-2;
    }
    if(cnt1>0)
    {
        if(cnt1%4==0)
        {
            total=total+cnt1/4;
        }
        else
        {
            total=total+cnt1/4+1;
        }
    }
    printf("%lld",total);
    return 0;
}