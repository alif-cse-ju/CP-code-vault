#include<bits/stdc++.h>
using namespace std;
int x[1000010];
void check(int a,int n)
    int i;
    for(i=a; i<=n; i+=a)
    {
        x[i]=1;
    }
int main()
    int a,b,c,d,n,ans=0,i;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
    if(a==1 || b==1 || c==1 || d==1)
    {
        printf("%d",n);
    }
    else
    {
        check(a,n);
        check(b,n);
        check(c,n);
        check(d,n);
        for(i=1; i<=n; i++)
        {
            if(x[i]==1)
            {
                ans++;
            }
        }
        printf("%d",ans);
    }
    return 0;
}