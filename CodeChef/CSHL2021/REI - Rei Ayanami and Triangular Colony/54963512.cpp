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
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll dp[102][102];
void PreCal()
{
    int i,j;
    dp[1][1]=1;
    for(i=2;i<=100;i++)
    {
        for(j=1;j<=i;j++)dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
        dp[i][i]=(dp[i][i]+dp[i-1][i-1])%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n][n] << '\n';
    }
    return 0;
}