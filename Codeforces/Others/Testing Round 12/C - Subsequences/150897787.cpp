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
const int M=1e5+5;
const int N=2e6+5;
const int mod=998244353;
int a[M],n;
ll dp[M][15];
void Update(int i,int id,ll v)
    while(i <= n)dp[i][id] += v, i += (i & -i);
ll Query(int i,int id)
    ll ans=0;
    while(i)ans += dp[i][id], i -= (i & -i);
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0,v;
    int i,j,k,p;
    cin >> n >> k, ++k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j == 1)v=1;
            else v=Query(a[i]-1,j-1);
            Update(a[i],j,v);
        }
        ans += v;
    }
    cout << ans;
    return 0;
}