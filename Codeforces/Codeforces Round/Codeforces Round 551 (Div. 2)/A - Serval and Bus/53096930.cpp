#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int b[105];
pair<int,int>a[105],tmp;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,t,mark=INT_MAX,ans,x;
    scanf("%d %d",&n,&t);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&x);
        scanf("%d",&b[i]);
        if(x < mark)
        {
            mark=x;
            ans=i;
        }
        tmp.first=x;
        tmp.second=i;
        a[i]=tmp;
    }
    if(mark >= t)
    {
        printf("%d",ans);
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            while(a[i].first < t)
            {
                a[i].first+=b[i];
            }
        }
        sort(a+1,a+n+1);
        printf("%d",a[1].second);
    }
    return 0;
}