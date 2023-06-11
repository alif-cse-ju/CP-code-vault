#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M],b[M];
int main()
{
    FAST();
    int i,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        reverse(b+1,b+n+1);
        ans=0;
        for(i=1;i<=n;i++)ans=max(ans,a[i]+b[i]);
        cout << ans << '\n';
    }
    return 0;
}