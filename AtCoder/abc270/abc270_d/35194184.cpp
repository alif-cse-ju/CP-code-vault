#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main(void){
    int n,k; cin>>n>>k;
    vector<int> a(k), dp(n+1);
    for(int i=0;i<k;i++) cin>>a[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(i<a[j]) break;
            dp[i] = max(dp[i],i-dp[i-a[j]]);
        }
    }
    cout<<dp[n]<<endl;
}
