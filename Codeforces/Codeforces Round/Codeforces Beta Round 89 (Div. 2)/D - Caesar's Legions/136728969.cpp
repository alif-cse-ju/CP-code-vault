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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e8;
int k1,k2;
ll dp[101][101][11][11];
ll DP(int n1,int n2,int kk1,int kk2)
    if(!n1)return (n2 <= kk2);
    if(!n2)return (n1 <= kk1);
    ll &ans=dp[n1][n2][kk1][kk2];
    if(ans != -1)return ans;
    ans=0;
    if(kk1)ans += DP(n1-1,n2,kk1-1,k2);
    if(kk2)ans += DP(n1,n2-1,k1,kk2-1);
    return ans %= mod;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp,-1,sizeof(dp));
    cout << DP(n1,n2,k1,k2);
    return 0;
}