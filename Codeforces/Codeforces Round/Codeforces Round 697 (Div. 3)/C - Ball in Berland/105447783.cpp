#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
pair<int,int>a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,t;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> m >> m >> n;
        for(i=1;i<=n;i++)cin >> a[i].first;
        for(i=1;i<=n;i++)cin >> a[i].second;
        ans=0;
        sort(a+1,a+n+1);
        map<int,int>mp;
        for(i=n-1;i>0;i--)
        {
            if(a[i].first != a[i+1].first)break;
        }
        for(j=n;i>0;i--)
        {
            if(a[i].first != a[i+1].first)
            {
                while(j > i)mp[a[j--].second]++;
            }
            ans+=(n-j)-mp[a[i].second];
        }
        cout << ans << '\n';
    }
    return 0;
}