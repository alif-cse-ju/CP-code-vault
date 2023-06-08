#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int n;
long long a[N];
bool Check(long long val)
    int i;
    long long ans=0;
    for(i=1;i<=n;i++)
    {
        if(a[i] >= val-1)break;
        else ans+=val-a[i]-1;
    }
    return (ans < val);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t,tc;
    long long l,m,r,ans;
    cin >> t;
    for(tc=1;tc<=t;tc++)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        if(n == 2)cout << "Case #" << tc << ": " << a[1]+a[2]+1 << '\n';
        else
        {
            ans=0,l=0,r=1e10;
            while(l <= r)
            {
                m=(l+r) >> 1ll;
                if(Check(m))ans=m,l=m+1;
                else r=m-1;
            }
            cout << "Case #" << tc << ": " << ans << '\n';
        }
    }
    return 0;
}
//