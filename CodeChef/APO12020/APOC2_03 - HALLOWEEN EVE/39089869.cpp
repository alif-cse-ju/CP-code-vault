#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,ans=INT_MAX;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(i=k;i<=n;i++)ans=min(ans,a[i]-a[i-k+1]);
    cout << ans;
    return 0;
}