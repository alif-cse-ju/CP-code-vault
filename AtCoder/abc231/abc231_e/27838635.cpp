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
const int N=2e6+5;
const int mod=1e9+7;

int n;
ll a[62];
map<ll,ll>dp[62];

ll DP(int i,ll v)
{
    if(i == 1  ||  !v)return v;
    if(dp[i].find(v) != dp[i].end())return dp[i][v];
    return dp[i][v]=min(DP(i-1,v%a[i])+v/a[i], DP(i-1,a[i]-(v%a[i]))+v/a[i]+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll v;
    int i;
    cin >> n >> v;
    for(i=1;i<=n;i++)cin >> a[i];
    cout << DP(n,v);
    return 0;
}
