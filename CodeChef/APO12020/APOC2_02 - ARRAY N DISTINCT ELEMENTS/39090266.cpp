#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],sum[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n,t,cnt;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        set<long long>st;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            st.insert(a[i]);
            sum[i]=a[i]+sum[i-1];
        }
        j=st.size();
        if(j > k)cout << "0\n";
        else
        {
            ans=LLONG_MIN;
            cnt=0;
            map<long long,int>mp;
            for(i=1;i<k;i++)
            {
                if(mp.find(a[i]) == mp.end())++cnt;
                ++mp[a[i]];
            }
            for(i=k;i<=n;i++)
            {
                if(mp.find(a[i]) == mp.end())++cnt;
                ++mp[a[i]];
                if(cnt == j)ans=max(ans,sum[i]-sum[i-k]);
                --mp[a[i-k+1]];
                if(mp[a[i-k+1]] == 0)--cnt;
            }
            if(ans == LLONG_MIN)cout << "0\n";
            else cout << ans << '\n';
        }
    }
    return 0;
}