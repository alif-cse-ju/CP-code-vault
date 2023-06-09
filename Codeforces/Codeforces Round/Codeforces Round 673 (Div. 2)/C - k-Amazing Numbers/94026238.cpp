#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int ans[N],last[N],mn[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)last[i]=mn[i]=0,ans[i]=INT_MAX;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            mn[x]=max(mn[x],i-last[x]);
            last[x]=i;
        }
        for(i=1;i<=n;i++)
        {
            mn[i]=max(mn[i],n-last[i]+1);
            ans[mn[i]]=min(ans[mn[i]],i);
        }
        for(i=2;i<=n;i++)ans[i]=min(ans[i],ans[i-1]);
        for(i=1;i<=n;i++)
        {
            if(ans[i] == INT_MAX)cout << "-1";
            else cout << ans[i];
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;