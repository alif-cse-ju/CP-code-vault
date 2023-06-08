#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=5e6+5;
const int mod=1e9+7;
bool ache[N];
int dp[N],freq[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        for(int i=0;i<=m;i++)ache[i]=freq[i]=0, dp[i]=i;
        int mn=INT_MAX, mx=0;
        for(int i=0;i<n;i++)
        {
            int x;cin >> x;
            ache[x]=freq[x]=1;
            mn=min(mn, x), mx=max(mx, x);
        }
        int ans=mx-mn, cur=mx;
        for(int i=mx;i;i--)
        {
            for(ll j=1ll*i*i;j<=mx;j+=i)
            {
                if(ache[j])--freq[dp[j]];
                dp[j]=min(dp[j], dp[j/i]);
                if(ache[j])++freq[dp[j]];
            }
            while(!freq[cur])--cur;
            if(i <= mn)ans=min(ans, cur-i);
        }
        cout << ans << '\n';
    }
    return 0;
}