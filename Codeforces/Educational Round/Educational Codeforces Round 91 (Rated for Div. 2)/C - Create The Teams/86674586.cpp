#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    long long i,n,t,x,ans,cnt,a[100002];
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        ans=cnt=0;
        for(i=n;i>0;i--)
        {
            ++cnt;
            if(a[i]*cnt >= x)++ans,cnt=0;
        }
        cout << ans << '\n';
    }
    return 0;