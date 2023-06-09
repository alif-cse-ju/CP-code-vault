#include<bits/stdc++.h>
using namespace std;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a[3],n,i,j,check,ans=0;
    scanf("%d %d %d %d",&n,&a[0],&a[1],&a[2]);
    sort(a,a+3);
    for(i=0;i<=4000;i++)
    {
        for(j=0;j<=4000;j++)
        {
            check=n-a[2]*i-a[1]*j;
            if(check%a[0] == 0 && check >= 0)
            {
                ans=max(ans,i+j+check/a[0]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;