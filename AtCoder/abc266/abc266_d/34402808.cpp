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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll dp[M][5];
int A[M],T[M],tmp[M][5],X[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> T[i] >> X[i] >> A[i];
    for(int i=1;i<=n;i++)tmp[T[i]][X[i]]=A[i];
    for(int i=100000;i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            if(j > i)continue;
            dp[i][j]=dp[i+1][j];
            for(int k=j-1;k>=0;k--)dp[i][j]=max(dp[i][j], dp[i+j-k][k]);
            for(int k=j+1;k<5;k++)dp[i][j]=max(dp[i][j], dp[i+k-j][k]);
            dp[i][j] += tmp[i][j];
        }
    }
    cout << dp[0][0];
    return 0;
}
