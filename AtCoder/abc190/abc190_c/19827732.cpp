#include<bits/stdc++.h>

using namespace std;

const int N=1e2+5;
const int mod=1e9+7;

int k,m,n,ans,a[N],b[N],c[N],d[N],cnt[N];

void Solve(int cur)
{
    if(cur > k)
    {
        int check=0;
        for(int i=1;i<=m;i++)
        {
            if(cnt[a[i]]  &&  cnt[b[i]])++check;
        }
        ans=max(ans,check);
        return;
    }
    ++cnt[c[cur]];
    Solve(cur+1);
    --cnt[c[cur]];
    ++cnt[d[cur]];
    Solve(cur+1);
    --cnt[d[cur]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i;
    cin >> n >> m;
    for(i=1;i<=m;i++)cin >> a[i] >> b[i];
    cin >> k;
    for(i=1;i<=k;i++)cin >> c[i] >> d[i];
    Solve(1);
    cout << ans;
    return 0;
}