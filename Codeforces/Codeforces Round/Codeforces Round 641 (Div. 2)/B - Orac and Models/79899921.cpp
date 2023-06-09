#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,n,t,ans,a[100005],cnt[100005];
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i],cnt[i]=1;
        for(i=1;i<=n;i++)
        {
            for(j=i+i;j<=n;j+=i)
            {
                if(a[i] < a[j])cnt[j]=max(cnt[j],cnt[i]+1);
            }
            ans=max(ans,cnt[i]);
        }
        cout << ans << '\n';
    }
    return 0;