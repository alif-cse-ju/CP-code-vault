#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int dp[32][32][2];
int DP(int l,int r,bool id)
{
    if(l+1 == r)return 0;
    int &ans=dp[l][r][id];
    if(ans > -1)return ans;
    if(id)ans=0;
    else ans=INT_MAX;
    for(int i=l+1;i<r;i++)
    {
        if(id)ans=max(ans, DP(l,i,1) + DP(i,r,1));
        else ans=min(ans, DP(l,i,0) + DP(i,r,0));
    }
    ans += r-l;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        int m,n;cin >> n >> m;
        int l=DP(0,n+1,0);
        int r=DP(0,n+1,1);
        if(m < l)cout << "-1\n";
        else cout << m-min(m,r) << '\n';
    }
    return 0;
}