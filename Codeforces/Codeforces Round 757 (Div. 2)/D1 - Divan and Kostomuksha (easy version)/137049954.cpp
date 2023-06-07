#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e4+5;
const int N=5e6+5;
const int mod=1e9+7;
ll cnt[N],dp[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0,mxx;
    int i,j,mx=0,n,x;
    cin >> n;
    while(n--)cin >> x, mx=max(mx,x), ++cnt[x];
    for(i=1;i<N;i++)
    {
        for(j=i+i;j<N;j+=i)cnt[i]+=cnt[j];
        dp[i]=cnt[i]*i;
    }
    for(i=mx;i;i--)
    {
        mxx=0;
        for(j=i+i;j<=mx;j+=i)mxx=max(mxx,(cnt[i]-cnt[j])*i+dp[j]);
        dp[i]=max(dp[i],mxx);
        ans=max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}