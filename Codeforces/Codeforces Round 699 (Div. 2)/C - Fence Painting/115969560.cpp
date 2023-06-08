#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int a[M],b[M],c[M],ans[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        for(i=1;i<=m;i++)cin >> c[i],ans[i]=INT_MAX;
        vector<int>clr[n+1];
        for(i=1;i<=n;i++)
        {
            if(a[i] != b[i])clr[b[i]].emplace_back(i);
        }
        for(i=1;i<=n;i++)
        {
            if(a[i] == b[i]  &&  clr[b[i]].empty())clr[b[i]].emplace_back(i);
        }
        for(i=1;i<=m;i++)
        {
            if(!clr[c[i]].empty())
            {
                ans[i]=clr[c[i]].back();
                if((int)clr[c[i]].size() > 1)clr[c[i]].pop_back();
            }
        }
        if(ans[m] == INT_MAX)
        {
            cout << "NO\n";
            continue;
        }
        for(i=m-1;i;i--)
        {
            if(ans[i] == INT_MAX)ans[i]=ans[i+1];
        }
        for(i=1;i<=m;i++)a[ans[i]]=c[i];
        for(i=n;i  &&  a[i] == b[i];i--);
        if(i)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=1;i<=m;i++)cout << ans[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}