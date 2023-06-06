#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

int n;
bool visited[M][2];
long long a[M],dp[M][2][2];

void DP(int idx,bool sgn)
{
    if(visited[idx][sgn])return;
    visited[idx][sgn]=1;
    if(idx == n)
    {
        if(sgn)dp[idx][sgn][0]=a[idx];
        else dp[idx][sgn][0]=-a[idx];
        dp[idx][sgn][1]=1;
        return;
    }
    if(sgn)
    {
        DP(idx+1,0);
        DP(idx+1,1);
        dp[idx][1][0]+=a[idx]*dp[idx+1][0][1]+dp[idx+1][0][0];
        dp[idx][1][0]+=a[idx]*dp[idx+1][1][1]+dp[idx+1][1][0];
        dp[idx][1][1]+=dp[idx+1][0][1]+dp[idx+1][1][1];
        dp[idx][1][0]%=mod,dp[idx][1][1]%=mod;
    }
    else
    {
        DP(idx+1,1);
        dp[idx][0][0]=-a[idx]*dp[idx+1][1][1]+dp[idx+1][1][0];
        dp[idx][0][1]=dp[idx+1][1][1];
        dp[idx][0][0]%=mod;
    }
    if(dp[idx][sgn][0] < 0)dp[idx][sgn][0]+=mod;
    if(dp[idx][sgn][1] < 0)dp[idx][sgn][1]+=mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    cin >> n;
    for(i=1; i<=n; i++)cin >> a[i];
    if(n == 1)
    {
        cout << a[1];
        return 0;
    }
    DP(1,1);
    cout << dp[1][1][0];
    return 0;
}
