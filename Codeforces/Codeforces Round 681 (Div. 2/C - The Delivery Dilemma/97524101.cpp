#include<bits/stdc++.h>
 using namespace std;
 const int N=2e5+5;
long long sum[N];
pair<int,int>a[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i].first;
        for(i=1;i<=n;i++)
        {
            cin >> a[i].second;
            a[i].second*=(-1);
        }
        sort(a+1,a+n+1);
        sum[n+1]=0;
        for(i=n;i>0;i--)sum[i]=sum[i+1] - a[i].second;
        ans=LLONG_MAX;
        for(i=n;i>=0;i--)ans=min(ans,max((long long)a[i].first,sum[i+1]));
        cout << ans << '\n';
    }
    return 0;
}