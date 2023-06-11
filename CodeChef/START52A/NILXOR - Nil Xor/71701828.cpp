#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=5e6+5;
const int mod=998244353;
int dp[30][2],n[30],x[30];
int DP(int pos,bool small)
{
    if(pos < 0)return (small);
    int &ans=dp[pos][small];
    if(ans > -1)return ans;
    if(x[pos])ans=DP(pos-1,small);
    else
    {
        ans=DP(pos-1,small|n[pos]);
        if(small  ||  n[pos])ans += DP(pos-1,small);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int nn,xx; cin >> nn >> xx;
        for(int i=29;i>=0;i--)n[i]=((nn >> i) & 1), x[i]=((xx >> i) & 1), dp[i][0]=dp[i][1]=-1;
        cout << DP(29,0) << '\n';
    }
    return 0;
}