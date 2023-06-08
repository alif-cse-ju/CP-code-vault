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
const int M=1e2+5;
const int N=1e6+5;
const int mod=1e9+7;
int d,k;
ll dp[M][2];
ll DP(int rem,bool ok)
    if(!rem)return ok;
    ll &ans=dp[rem][ok];
    if(ans > -1)return ans;
    ans=0;
    for(int i=1;i<=min(k,rem);i++)ans=(ans+DP(rem-i,ok | (i >= d)))%mod;
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> k >> d;
    memset(dp,-1,sizeof(dp));
    cout << DP(n,0);
    return 0;
}