#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e3+5;
const int N=1e6+5;
const int mod=998244353;

ll dp[M][M];
int a[M],b[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    for(i=0;i<M;i++)dp[0][i]=1;
    for(i=1;i<=n;i++)
    {
        for(j=a[i];j<=b[i];j++)dp[i][j]=dp[i-1][j];
        for(j=1;j<M;j++)dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
    }
    cout << dp[n][M-1];
    return 0;
}
