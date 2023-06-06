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

const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;

const int sz = 2e3+5;

int t,X;
ll dp[sz][sz][2];
vector<int>adj[sz];

ll DP(int x,int k,bool odd)
{
    if(!k)
    {
        if(x == t  &&  !odd)return 1;
        return 0;
    }
    ll &ans=dp[x][k][odd];
    if(ans > -1)return ans;
    ans=0;
    for(int y : adj[x])
    {
        ans += DP(y,k-1,(y == X ? !odd : odd));
        if(ans >= mod)ans -= mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,m,n,s,y,z;
    cin >> n >> m >> k >> s >> t >> X;
    while(m--)
    {
        cin >> y >> z;
        adj[y].emplace_back(z);
        adj[z].emplace_back(y);
    }
    memset(dp,-1,sizeof(dp));
    cout << DP(s,k,0);
    return 0;
}