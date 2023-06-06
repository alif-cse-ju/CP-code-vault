#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;

const int sz=1e3+5;

int k,m,n;
ll dp[sz][5*sz][2];

ll DP(int i,int v,bool inc)
{
    if(i == n)
    {
        if(inc)return m-v+1;
        return v;
    }
    ll &ans=dp[i][v][inc];
    if(ans > -1)return ans;
    ans=0;
    if(inc  &&  v+1 <= m)
    {
        ans += DP(i,v+1,1);
        if(ans >= mod)ans -= mod;
    }
    else if(!inc  &&  v-1)
    {
        ans += DP(i,v-1,0);
        if(ans >= mod)ans -= mod;
    }
    if(v+k <= m)
    {
        ans += DP(i+1,v+k,1);
        if(ans >= mod)ans -= mod;
    }
    if(v-max(1,k) > 0)
    {
        ans += DP(i+1,v-max(1,k),0);
        if(ans >= mod)ans -= mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    memset(dp,-1,sizeof(dp));
    cout << DP(1,1,1);
    return 0;
}