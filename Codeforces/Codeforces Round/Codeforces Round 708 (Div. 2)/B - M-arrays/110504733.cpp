#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=0;i<m;i++)cnt[i]=0;
        while(n--)
        {
            cin >> x;
            ++cnt[x%m];
        }
        ans=(cnt[0] > 0);
        for(i=1;i<(m+1)/2;i++)
        {
            x=min(cnt[i],cnt[m-i]);
            cnt[i]-=x,cnt[m-i]-=x;
            ans+=(x > 0)+max(0,cnt[i]-(x > 0))+max(0,cnt[m-i]-(x > 0));
        }
        if(!(m & 1))ans+=(cnt[m/2] > 0);
        cout << ans << '\n';
    }
    return 0;