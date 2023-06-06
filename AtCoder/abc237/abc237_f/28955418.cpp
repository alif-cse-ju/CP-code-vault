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

const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;

const int sz = (1 << 10);
int m,n;
ll dp[1000][12][12][12];

ll DP(int idx,int lis1,int lis2,int lis3)
{
    if(idx == n)return (lis3 < m);
    ll &ans=dp[idx][lis1][lis2][lis3];
    if(ans > -1)return ans;
    int i;
    ans=0;
    for(i=0;i<m;i++)
    {
        if(i > lis3)continue;
        if(lis1 >= i)ans += DP(idx+1,min(lis1,i),lis2,lis3);
        else if(lis2 < i)ans += DP(idx+1,lis1,lis2,i);
        else ans += DP(idx+1,lis1,i,lis3);
        if(ans >= mod)ans -= mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(dp,-1,sizeof(dp));
    cout << DP(0,m,m,m);
    return 0;
}
