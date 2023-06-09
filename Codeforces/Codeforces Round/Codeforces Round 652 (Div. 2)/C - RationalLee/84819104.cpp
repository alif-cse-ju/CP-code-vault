#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL mn[200002],mx[200002],cnt[200002];
int main()
    FAST();
    LL ans;
    int i,k,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<int>v;
        for(i=0;i<n;i++)
        {
            cin >> x;
            v.emplace_back(x);
        }
        sort(v.begin(),v.end());
        for(i=1;i<=k;i++)cin >> cnt[i];
        sort(cnt+1,cnt+k+1);
        for(i=1;i<=k;i++)
        {
            mx[i]=v.back();
            v.pop_back(),cnt[i]--;
        }
        for(i=1;i<=k;i++)
        {
            while(cnt[i] > 1)--cnt[i],v.pop_back();
            if(cnt[i] > 0)
            {
                mn[i]=v.back();
                v.pop_back();
            }
            else mn[i]=mx[i];
        }
        ans=0;
        for(i=1;i<=k;i++)ans+=mn[i]+mx[i];
        cout << ans << '\n';
    }
    return 0;
}