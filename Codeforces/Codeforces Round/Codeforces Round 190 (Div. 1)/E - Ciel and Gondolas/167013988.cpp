#pragma GCC optimize("Ofast")
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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 4e3+5;
const int K = 805;
int cost[sz][sz],dp[K][sz],opt[K][sz],tmp[sz][sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin >> tmp[i][j], tmp[i][j]+=tmp[i][j-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)cost[i][j]=cost[i][j-1]+tmp[j][j]-tmp[j][i-1];
    }
    for(int i=1;i<=k;i++)opt[i][n+1]=n;
    for(int i=1;i<=n;i++)dp[0][i]=1e9, opt[0][i]=1;
    for(int grpNo=1;grpNo<=k;grpNo++)
    {
        for(int i=n;i;i--)
        {
            dp[grpNo][i]=INT_MAX;
            for(int j=opt[grpNo-1][i];j<=opt[grpNo][i+1];j++)
            {
                int tmp=dp[grpNo-1][j-1]+cost[min(i,j)][max(i,j)];
                if(tmp < dp[grpNo][i])dp[grpNo][i]=tmp, opt[grpNo][i]=j;
            }
        }
    }
    cout << dp[k][n];
    return 0;
}