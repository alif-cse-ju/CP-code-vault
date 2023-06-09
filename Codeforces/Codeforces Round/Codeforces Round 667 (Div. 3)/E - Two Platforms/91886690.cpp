#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int X[N],cnt[N],mx[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t,x,ans,cur;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> X[i];
        for(i=1;i<=n;i++)cin >> x;
        sort(X+1,X+n+1);
        for(i=1;i<n;i++)
        {
            auto it=upper_bound(X+1,X+n+1,X[i]+k)-X;
            cnt[i]=(int)it-i;
        }
        cnt[n]=mx[n]=1;
        for(i=n-1;i>0;i--)mx[i]=max(cnt[i],mx[i+1]);
        ans=0;
        for(i=1;i<=n;i++)
        {
            cur=cnt[i];
            if(i+cnt[i] <= n)cur+=mx[i+cnt[i]];
            ans=max(ans,cur);
        }
        cout << ans << '\n';
    }
    return 0;