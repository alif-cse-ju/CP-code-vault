#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5;
vector<int>adj[M];
int ans[M],cnt[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            cnt[i]=0;
            adj[i].clear();
        }
        while(m--)
        {
            cin >> x >> y;
            ++cnt[x], ++cnt[y];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        set<pair<int,int>>st;
        for(i=1;i<=n;i++)st.insert({cnt[i],i});
        for(i=n;i;i--)
        {
            auto [v,id]=*(st.begin());
            st.erase(st.begin());
            for(int it : adj[id])
            {
                if(st.find({cnt[it],it}) != st.end())
                {
                    st.erase({cnt[it],it});
                    st.insert({--cnt[it],it});
                }
            }
            ans[id]=i;
        }
        for(i=1;i<=n;i++)
        {
            cnt[i]=0;
            for(int it : adj[i])cnt[i] += (ans[it] < ans[i]);
        }
        sort(cnt+1,cnt+n+1);
        cout << cnt[n]-cnt[1] << '\n';
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}