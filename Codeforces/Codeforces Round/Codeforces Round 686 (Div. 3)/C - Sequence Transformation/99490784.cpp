#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int last[N],cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,l,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)last[i]=cnt[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            cnt[x]+=min(1,i-last[x]-1);
            last[x]=i;
        }
        for(i=1;i<=n;i++)
        {
            if(!last[i])cnt[i]=INT_MAX;
            else cnt[i]+=min(1,n-last[i]);
        }
        ans=INT_MAX;
        for(i=1;i<=n;i++)ans=min(ans,cnt[i]);
        cout << ans << '\n';
    }
    return 0;