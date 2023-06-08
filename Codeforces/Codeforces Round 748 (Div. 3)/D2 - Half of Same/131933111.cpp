#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int cnt[N],_tm[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n+5];
        for(i=1; i<=n; i++)cin >> a[i],a[i] += 1e6;
        ans=1;
        sort(a+1,a+n+1);
        for(i=2; i<=n; i++)a[i] -= a[1];
        a[1]=0;
        for(i=0; i<=a[n]; i++)_tm[i]=0;
        for(i=1; i<=n; i++)
        {
            if(_tm[a[i]] == 1)++cnt[a[i]];
            else _tm[a[i]]=1, cnt[a[i]]=1;
            if(cnt[a[i]] >= n/2)ans=INT_MAX;
        }
        if(ans != INT_MAX)
        {
            for(i=a[n]; i>1 && ans == 1; i--)
            {
                for(j=1; j<=n; j++)
                {
                    if(_tm[a[j]%i] == i)++cnt[a[j]%i];
                    else _tm[a[j]%i]=i, cnt[a[j]%i]=1;
                    if(cnt[a[j]%i] >= n/2)ans=i;
                }
            }
        }
        if(ans == INT_MAX)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}