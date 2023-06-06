#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;
const int mod=1e9+7;

int a[N],cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,ans;
    set<int>st;
    for(i=0;i<N;i++)st.insert(i);
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)
    {
        ++cnt[a[i]];
        if(cnt[a[i]] == 1)st.erase(a[i]);
    }
    ans=*(st.begin());
    for(i=m+1;i<=n;i++)
    {
        --cnt[a[i-m]];
        if(!cnt[a[i-m]])st.insert(a[i-m]);
        ++cnt[a[i]];
        if(cnt[a[i]] == 1)st.erase(a[i]);
        ans=min(ans,*(st.begin()));
    }
    cout << ans;
    return 0;
}
//