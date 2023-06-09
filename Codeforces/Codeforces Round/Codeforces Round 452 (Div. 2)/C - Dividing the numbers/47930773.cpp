#include<bits/stdc++.h>
using namespace std;
int ans[60010];
int main()
    int i,n,sum1=0,sum2=0,len=0;
    scanf("%d",&n);
    if(n%2 == 0)
    {
        for(i=1; i<n; i+=2)
        {
            if(sum1 < sum2)
            {
                sum1+=(i+1);
                sum2+=i;
                ans[len++]=i+1;
            }
            else
            {
                sum1+=i;
                sum2+=(i+1);
                ans[len++]=i;
            }
        }
    }
    else
    {
        for(i=n; i>1; i-=2)
        {
            if(sum1 >= sum2)
            {
                sum1+=(i-1);
                sum2+=i;
                ans[len++]=i-1;
            }
            else
            {
                sum1+=i;
                sum2+=(i-1);
                ans[len++]=i;
            }
        }
        if(sum1<sum2)
        {
            sum1++;
            ans[len++]=1;
        }
        else
        {
            sum2++;
        }
    }
    printf("%d\n",abs(sum1-sum2));
    sort(ans,ans+len);
    printf("%d",len);
    for(i=0; i<len; i++)
    {
        printf(" %d",ans[i]);
    }
    return 0;
}