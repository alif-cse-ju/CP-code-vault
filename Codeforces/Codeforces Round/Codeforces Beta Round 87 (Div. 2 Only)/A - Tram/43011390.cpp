#include<bits/stdc++.h>
using namespace std;
int main()
    int n,i,a,b;
    long long int max,cnt;
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    max=b,cnt=b;
    for(i=2; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        cnt=cnt+b-a;
        if(cnt>max)
        {
            max=cnt;
        }
    }
    scanf("%d%d",&a,&b);
    printf("%lld",max);
    return 0;