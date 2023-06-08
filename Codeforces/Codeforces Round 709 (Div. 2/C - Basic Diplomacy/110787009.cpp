#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int ans[N],cnt[N];
vector<int>avail[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,j,k,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cnt[i]=0;
        for(i=1;i<=m;i++)
        {
            ans[i]=0;
            avail[i].clear();
            cin >> k;
            while(k--)
            {
                cin >> x;
                avail[i].emplace_back(x);
            }
            sort(avail[i].begin(),avail[i].end());
        }
        for(i=1;i<=m;i++)
        {
            ans[i]=avail[i][0];
            ++cnt[avail[i][0]];
        }
        for(i=1;i<=m;i++)
        {
            if(cnt[ans[i]] > (m+1)/2)
            {
                k=(int)avail[i].size();
                for(j=1;j<k;j++)
                {
                    if(cnt[avail[i][j]] < (m+1)/2)
                    {
                        --cnt[ans[i]];
                        ans[i]=avail[i][j];
                        ++cnt[ans[i]];
                    }
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            if(cnt[ans[i]] > (m+1)/2)
            {
                k=(int)avail[i].size();
                for(j=1;j<k;j++)
                {
                    if(cnt[avail[i][j]] < (m+1)/2)
                    {
                        --cnt[ans[i]];
                        ans[i]=avail[i][j];
                        ++cnt[ans[i]];
                    }
                }
            }
        }
        flag=1;
        for(i=1;i <= n  &&  flag;i++)
        {
            if(cnt[i] > (m+1)/2)flag=0;
        }
        if(flag)
        {
            cout << "YES\n";
            for(i=1;i<=m;i++)cout << ans[i] << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }
    return 0;
}
//