#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,cnt;
    long long ans=0;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)cin >> b[i];
    b[0]=INT_MIN;
    for(i=j=1;j<=m;j++)
    {
        if(b[j] != b[j-1])cnt=0;
        while(i <= n  &&  a[i] <= b[j])
        {
            if(a[i] == b[j])++cnt;
            i++;
        }
        ans+=cnt;
    }
    cout << ans;
    return 0;