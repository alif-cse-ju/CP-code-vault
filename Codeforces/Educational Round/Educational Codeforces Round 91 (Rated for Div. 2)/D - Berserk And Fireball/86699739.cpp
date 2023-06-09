#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL a[200002],b[200002];
int main()
    FAST();
    int i,j=1,k,m,n;
    LL x,y,ans=0,cnt=0,mn,mx=0;
    cin >> n >> m;
    cin >> x >> k >> y;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)cin >> b[i];
    a[n+1]=b[m+1]=0;
    for(i=1;i<=n+1;i++)
    {
        if(a[i] == b[j])
        {
            mn=LLONG_MAX;
            if(b[j-1] > mx  ||  b[j] > mx)mn=cnt*y;
            if(cnt >= k)mn=min(mn,(cnt/k)*x+(cnt%k)*y);
            if(cnt >= k)mn=min(mn,x+(cnt-k)*y);
            if(mn == LLONG_MAX)
            {
                cout << "-1";
                return 0;
            }
            mx=cnt=0;
            ++j,ans+=mn;
        }
        else ++cnt,mx=max(mx,a[i]);
    }
    if(j <= m)cout << "-1";
    else cout << ans;
    return 0;
}