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

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll dp[102][M];
int v[102],w[102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; ll W; cin >> n >> W;
    for(int i=1;i<=n;i++)cin >> w[i] >> v[i];

    for(int j=1;j<M;j++)dp[0][j]=1000000000000;

    for(int i=1;i<=n;i++)
    {
            for(int j=0;j<M;j++)
            {
                    dp[i][j]=dp[i-1][j];
                    if(j >= v[i])dp[i][j]=min(dp[i][j], dp[i-1][j-v[i]]+w[i]);
            }
    }

    for(int i=M-1;i>=0;i--)
    {
            if(dp[n][i] <= W)
            {
                    cout << i;
                    return 0;
            }
    }
    return 0;
}