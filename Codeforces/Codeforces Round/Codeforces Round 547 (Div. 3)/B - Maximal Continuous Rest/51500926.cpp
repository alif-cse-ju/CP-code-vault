#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,cnt=0,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i] == 1)
        {
            cnt++;
        }
        else
        {
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    if(cnt > 0 && cnt<n)
    {
        i=1;
        while(a[i] != 0)
        {
            cnt++;
            i++;
        }
    }
    ans=max(cnt,ans);
    printf("%d",ans);
    return 0;
}
 