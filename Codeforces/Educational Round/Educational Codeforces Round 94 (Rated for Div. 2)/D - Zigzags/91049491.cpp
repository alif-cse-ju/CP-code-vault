#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int cnt[N+2][N+2];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long ans;
    int i,j,n,t,x,y,a[N+2];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)cnt[i][j]=0;
        }
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            ++cnt[a[i]][i];
        }
        for(i=1;i<=n;i++)
        {
            for(j=2;j<=n;j++)cnt[i][j]+=cnt[i][j-1];
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                x=cnt[a[j]][i-1];
                y=cnt[a[i]][n]-cnt[a[i]][j];
                ans+=x*y;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}