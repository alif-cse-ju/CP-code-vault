#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
pair<long long,long long>a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i].first >> a[i].second;
    sort(a+1,a+n+1);
    long long ans=0,mx=a[1].first+a[1].second;
    for(i=1;i<=n;i++)ans+=a[i].second;
    for(i=2;i<=n;i++)
    {
        ans+=max(0ll,a[i].first-mx);
        mx=max(mx,a[i].first+a[i].second);
    }
    cout << ans;
    return 0;