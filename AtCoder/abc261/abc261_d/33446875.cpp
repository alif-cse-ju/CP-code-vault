#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int sz=5e3+5;

ll dp[sz][sz],x[sz],y[sz],n;

ll DP(int cur,int moveNum)
{
    if(moveNum > n)return y[cur];
    ll &ans=dp[cur][moveNum];
    if(ans > -1)return ans;
    ans=y[cur];
    ans += max(DP(0,moveNum+1), DP(cur+1,moveNum+1)+x[moveNum]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> x[i];
    while(m--){int c;cin >> c >> y[c];}
    memset(dp,-1,sizeof(dp));
    cout << DP(0,1);
    return 0;
}
