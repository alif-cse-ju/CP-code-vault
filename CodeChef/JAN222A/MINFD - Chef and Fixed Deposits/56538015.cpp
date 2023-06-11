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
const int N=1e6+5;
const int mod=1e9+7;
int a[102],dp[102][10002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        if(a[n] >= x)cout << "1\n";
        else
        {
            for(i=1;i<=1e4;i++)dp[0][i]=200;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<a[i];j++)dp[i][j]=dp[i-1][j];
                for(j=a[i];j<=1e4;j++)dp[i][j]=min(dp[i-1][j], dp[i-1][j-a[i]] + 1);
            }
            for(i=1e4;i>x;i--)dp[n][x]=min(dp[n][x], dp[n][i]);
            if(dp[n][x] > n)dp[n][x]=-1;
            cout << dp[n][x] << '\n';
        }
    }
    return 0;
}