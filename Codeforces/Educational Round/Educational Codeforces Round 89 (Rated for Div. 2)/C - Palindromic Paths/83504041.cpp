#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,m,n,t,x,ans,cnt[32][2];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin >> x;
                if(i+j == m+n+2-i-j)continue;
                ++cnt[min(i+j,m+n+2-i-j)][x];
            }
        }
        ans=0;
        for(i=2;i<31;i++)ans+=min(cnt[i][0],cnt[i][1]);
        cout << ans << '\n';
    }
    return 0;