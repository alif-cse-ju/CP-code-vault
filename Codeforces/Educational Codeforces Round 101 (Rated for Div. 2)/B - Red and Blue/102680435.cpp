#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[102],b[102];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,t,mx1,mx2,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        cin >> m;
        for(i=1;i<=m;i++)cin >> b[i];
        mx1=cnt=0;
        for(i=1;i<=n;i++)
        {
            cnt+=a[i];
            mx1=max(mx1,cnt);
        }
        mx2=cnt=0;
        for(i=1;i<=m;i++)
        {
            cnt+=b[i];
            mx2=max(mx2,cnt);
        }
        cout << mx1+mx2 << '\n';
    }
    return 0;