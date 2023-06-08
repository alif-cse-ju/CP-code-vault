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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int col[M],dp[21][1 << 20];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string s;cin >> s;
        for(int j=0;j<m;j++)
        {
            if(s[j] == '1')col[j] += (1 << i);
        }
    }
    for(int i=0;i<m;i++)++dp[0][col[i]];
    for(int i=1;i<=n;i++)
    {
        for(int mask=0;mask<(1 << n);mask++)
        {
            int sum=0;
            if(i >= 2)sum -= (n-(i-2))*dp[i-2][mask];
            for(int j=0;j<n;j++)sum += dp[i-1][mask ^ (1 << j)];
            dp[i][mask]=sum/i;
        }
    }
    int ans=m*n;
    for(int mask=0;mask<(1 << n);mask++)
    {
        int tmp=0;
        for(int i=0;i<=n;i++)tmp += min(i,n-i)*dp[i][mask];
        ans=min(ans, tmp);
    }
    cout << ans;
    return 0;
}