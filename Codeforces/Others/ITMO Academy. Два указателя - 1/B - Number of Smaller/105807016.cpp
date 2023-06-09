#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],b[N],ans[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)cin >> b[i];
    for(i=j=1;i<=m;i++)
    {
        while(j <= n  &&  a[j] < b[i])++j;
        ans[i]=j-1;
    }
    for(i=1;i<=m;i++)cout << ans[i] << ' ';
    return 0;