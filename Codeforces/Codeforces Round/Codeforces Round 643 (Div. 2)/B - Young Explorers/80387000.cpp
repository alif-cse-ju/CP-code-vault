#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,ans,cnt[300005];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cnt[i]=0;
        for(i=1;i<=n;i++)cin >> x,++cnt[x];
        ans=0;
        for(i=1;i<=n;i++)
        {
            cnt[i]+=cnt[i-1];
            ans+=cnt[i]/i;
            cnt[i]%=i;
        }
        cout << ans << '\n';
    }
    return 0;