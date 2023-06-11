#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int cnt[M][32],cnt0[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int n;cin >> n;
            for(int i=1;i<=n;i++)
            {
                    int x;cin >> x;
                    cnt0[i]=cnt0[i-1];
                    for(int j=30;j>=0;j--)cnt[i][j]=cnt[i-1][j];
                    if(!x)
                    {
                            ++cnt0[i];
                            continue;
                    }
                    for(int j=30;j>=0;j--)
                    {
                            if((x >> j) & 1)
                            {
                                    ++cnt[i][j];
                                    break;
                            }
                    }
            }
            int q;cin >> q;
            while(q--)
            {
                    int l,r,x;cin >> l >> r >> x;
                    int msb=-1;
                    for(int i=30;i>=0;i--)
                    {
                            if((x >> i) & 1)
                            {
                                    msb=i;
                                    break;
                            }
                    }
                    int ans=0;
                    for(int i=msb+1;i<31;i++)ans += cnt[r][i]-cnt[l-1][i];
                    for(int i=msb-1;i>=0;i--)ans += cnt[r][i]-cnt[l-1][i];
                    if(x)ans += cnt0[r]-cnt0[l-1];
                    cout << ans << '\n';
            }
    }
    return 0;
}