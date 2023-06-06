#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5;
const int mod=1e9+7;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,ans=INT_MAX;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i] >> b[i];
    for(i=1;i<=n;i++)
    {
        ans=min(ans,a[i]+b[i]);
        for(j=1;j<i;j++)ans=min(ans,max(a[i],b[j]));
        for(j=i+1;j<=n;j++)ans=min(ans,max(a[i],b[j]));
    }
    cout << ans;
    return 0;
}