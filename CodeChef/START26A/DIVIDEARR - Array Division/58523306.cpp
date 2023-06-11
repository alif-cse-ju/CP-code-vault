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
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 1e3+5;
int a[sz],dp[sz][sz],n;
int DP(int i,int A,int B)
{
    if(i > n)return 0;
    int &ans=dp[A][B];
    if(ans > -1)return ans;
    ans=max(ans, abs(a[i]-a[(A > 0 ? A : i)]) + DP(i+1,i,B));
    ans=max(ans, abs(a[i]-a[(B > 0 ? B : i)]) + DP(i+1,A,i));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)dp[i][j]=-1;
        }
        cout << DP(1,0,0) << '\n';
    }
    return 0;
}