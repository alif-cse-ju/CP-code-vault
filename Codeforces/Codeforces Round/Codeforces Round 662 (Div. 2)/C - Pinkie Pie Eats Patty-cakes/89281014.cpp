#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,mx,ans,cnt[100002];
    cin >> t;
    while(t--)
    {
        cin >> n;
        mx=ans=0;
        for(i=1;i<=n;i++)cnt[i]=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            ++cnt[x];
            mx=max(mx,cnt[x]);
        }
        for(i=1;i<=n;i++)ans+=min(mx-1,cnt[i]);
        ans-=mx-1;
        cout << ans/(mx-1) << '\n';
    }
    return 0;