#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll dp[102][102][102];
ll DP(int n,int r,int u)
{
    if(u > r)return 0;
    if(r == n  &&  u == n)return 1;
    ll &ans=dp[n][r][u];
    if(ans != -1)return ans;
    ans=0;
    if(r < n)ans += DP(n,r+1,u);
    if(u < n)ans += DP(n,r,u+1);
    return ans %= mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    memset(dp,-1,sizeof(dp));
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << DP(n,0,0) << '\n';
    }
    return 0;
}