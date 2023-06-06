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

const int sz = 2e3+1;

int m,n;
char grid[sz][sz];
ll c[sz],dp[sz][2][sz][2],r[sz];

ll DP(int i,int j,bool R,bool C)
{
    if(i == n  &&  j == m)return 0;
    ll &ans=dp[i][R][j][C];
    if(ans > -1)return ans;
    ans=1e16;
    int v=((grid[i][j]-'0')+C+R)%2;
    if(i < n)
    {
        int vv=((grid[i+1][j]-'0')+C)%2;
        if(v == vv)ans=min(ans, DP(i+1,j,0,C));
        else ans=min(ans, DP(i+1,j,1,C)+r[i+1]);
    }
    if(j < m)
    {
        int vv=((grid[i][j+1]-'0')+R)%2;
        if(v == vv)ans=min(ans, DP(i,j+1,R,0));
        else ans=min(ans, DP(i,j+1,R,1)+c[j+1]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> r[i];
    for(int i=1;i<=m;i++)cin >> c[i];
    for(int i=1;i<=n;i++)cin >> grid[i]+1;
    memset(dp,-1,sizeof(dp));
    cout << min({DP(1,1,0,0), DP(1,1,0,1)+c[1], DP(1,1,1,0)+r[1], DP(1,1,1,1)+c[1]+r[1]});
    return 0;
}
