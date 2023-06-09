#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],cum[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,int>cnt;
        while(n--)
        {
            cin >> x;
            ++cnt[x];
        }
        n=0;
        for(auto it : cnt)a[++n]=it.second;
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)cum[i]=cum[i-1]+a[i];
        ans=INT_MAX;
        for(i=1;i<=a[n];i++)
        {
            auto it=lower_bound(a+1,a+n+1,i)-a;
            ans=min(ans,cum[n]-(n-(int)it+1)*i);
        }
        cout << ans << '\n';
    }
    return 0;