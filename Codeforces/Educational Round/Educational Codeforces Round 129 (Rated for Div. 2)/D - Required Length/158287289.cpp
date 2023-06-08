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
const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;
int n;
map<ll,int>dp;
int DP(ll x)
    if((int)to_string(x).size() >= n)return 0;
    if(dp.find(x) != dp.end())return dp[x];
    vector<bool>mark(10, 0);
    ll y=x;
    while(y)mark[y%10]=1, y/=10;
    int ans=75;
    for(int i=2;i<10;i++)
    {
        if(mark[i])ans=min(ans, DP(x*i)+1);
    }
    return dp[x]=ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;cin >> n >> x;
    if((int)to_string(x).size() >= n)cout << "0";
    else
    {
        ll ans=DP(x);
        if(ans > 70)cout << "-1";
        else cout << ans;
    }
    return 0;
}