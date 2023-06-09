#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int a[N],cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,l,n,r,ans=0,cur=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    a[n+1]=N-4;
    for(l=r=1;l<=n;l++)
    {
        r=max(l,r);
        while(true)
        {
            if(cnt[a[r]])++cnt[a[r]];
            else
            {
                if(cur+a[r] <= k)
                {
                    cur+=a[r];
                    ++cnt[a[r]];
                }
                else break;
            }
            ++r;
        }
        ans=max(ans,r-l);
        if(cnt[a[l]])
        {
            --cnt[a[l]];
            if(!cnt[a[l]])cur-=a[l];
        }
    }
    cout << ans;
    return 0;
}