#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cnt[i]=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            ++cnt[x];
        }
        ans=0;
        for(i=1;i<=n;i++)ans+=(cnt[i]*(cnt[i]-1)*(cnt[i]-2))/6;
        for(i=1;i<n;i++)
        {
            ans+=((cnt[i]*(cnt[i]-1))/2)*(cnt[i+1]);
            ans+=((cnt[i+1]*(cnt[i+1]-1))/2)*(cnt[i]);
        }
        for(i=1;i<n-1;i++)
        {
            ans+=((cnt[i]*(cnt[i]-1))/2)*(cnt[i+2]);
            ans+=((cnt[i+2]*(cnt[i+2]-1))/2)*(cnt[i]);
            ans+=(cnt[i]*cnt[i+1]*cnt[i+2]);
        }
        cout << ans << '\n';
    }
    return 0;
}