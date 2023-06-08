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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[505],d[505],dp[501][501],n;
int DP(int cur,int rem)
    if(cur == n)return 0;
    int &ans=dp[cur][rem];
    if(ans != -1)return ans;
    ans=INT_MAX;
    for(int i=cur+1;i<=min(n,cur+rem+1);i++)ans=min(ans, DP(i,rem+cur+1-i) + (d[i]-d[cur])*a[cur]);
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,l;
    cin >> n >> l >> k;
    for(i=1;i<=n;i++)cin >> d[i];
    for(i=1;i<=n;i++)cin >> a[i];
    ++n, d[n]=l;
    memset(dp,-1,sizeof(dp));
    cout << DP(1,k);
    return 0;
}