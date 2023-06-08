#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int c[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,i,m,n,t,ans,mx,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a >> b;
        for(i=1;i<=m;i++)cin >> c[i];
        cnt=min(m,abs(a-b)-1);
        if(a < b)mx=b-1;
        else mx=n-b;
        ans=0;
        sort(c+1,c+m+1);
        for(i=cnt;i>0;i--)
        {
            if(c[i]+ans+1 <= mx)++ans;
        }
        cout << ans << '\n';
    }
    return 0;