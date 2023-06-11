#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll j,X,xr;
    int cnt,i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        X=xr=0;
        for(j=0;j<61;j++)
        {
            cnt=0;
            for(i=1;i<=n;i++)cnt += ((a[i] >> j) & 1ll);
            if(cnt & 1)
            {
                X += (1ll << j);
                for(i=1;i<=n;i++)a[i] += (1ll << j);
            }
        }
        for(i=1;i<=n;i++)xr ^= a[i];
        if(xr)cout << "-1\n";
        else cout << X << '\n';
    }
    return 0;
}