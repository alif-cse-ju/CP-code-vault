#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n;
    long long ans=0;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(i=1;i<=m;i++)
    {
        if(b[i] < a[1])ans+=n;
        else break;
    }
    cout << ans;
    return 0;
}