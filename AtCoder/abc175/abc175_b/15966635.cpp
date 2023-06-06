#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,j,k,n,x,ans=0,cnt,a[102];
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i] == a[j])continue;
            cnt=0;
            x=a[i]+a[j];
            for(k=j+1;k<=n;k++)
            {
                if(a[k] == a[j])continue;
                if(a[k] < x)++cnt;
                else break;
            }
            ans+=cnt;
        }
    }
    cout << ans;
    return 0;
}
