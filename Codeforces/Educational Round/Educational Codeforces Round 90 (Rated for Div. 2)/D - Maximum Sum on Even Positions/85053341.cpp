#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t;
    LL a[200002],ans,cnt,mx1,mx2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<LL>v1,v2;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=a[1];
        for(i=2;i<=n;i++)
        {
            if(i & 1)ans+=a[i],v1.emplace_back(a[i-1]-a[i]);
            else v2.emplace_back(a[i]-a[i-1]);
        }
        cnt=0;
        mx1=INT_MIN;
        for(LL x : v1)
        {
            cnt+=x;
            if(cnt < 0)cnt=0;
            mx1=max(cnt,mx1);
        }
        cnt=0;
        mx2=INT_MIN;
        for(LL x : v2)
        {
            cnt+=x;
            if(cnt < 0)cnt=0;
            mx2=max(cnt,mx2);
        }
        ans+=max(0LL,max(mx1,mx2));
        cout << ans << '\n';
    }
    return 0;
}