#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int sz = 5e3+5;
ll dp[2][sz+sz],l[sz],r[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p;cin >> n >> p;
    vector<int>v; v.emplace_back(p);
    for(int i=1;i<=n;i++)
    {
        cin >> l[i] >> r[i];
        v.emplace_back(l[i]), v.emplace_back(r[i]);
    }
    sort(v.begin(),v.end());
    int ln=(int)v.size();
    for(int i=0;i<ln;i++)dp[0][i]=abs(p-v[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<ln;j++)
        {
            dp[i%2][j]=dp[1-i%2][j];
            if(v[j] < l[i])dp[i%2][j] += l[i]-v[j];
            else if(v[j] > r[i])dp[i%2][j] += v[j]-r[i];
        }
        for(int j=0;j+1<ln  &&  v[j] < l[i];j++)
        {
            if(dp[i%2][j] < dp[i%2][j+1])dp[i%2][j+1] = dp[i%2][j];
        }
        for(int j=ln-1;j  &&  v[j] > r[i];j--)
        {
            if(dp[i%2][j] < dp[i%2][j-1])dp[i%2][j-1] = dp[i%2][j];
        }
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<ln;i++)ans=min(ans, dp[n%2][i]);
    cout << ans;
    return 0;
}