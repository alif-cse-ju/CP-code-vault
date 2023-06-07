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
const int N=1e6+5;
const int mod=1e9+7;
vector<int>adj[M];
int a[M],b[M],c[M],dp[M][30];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<30;j++)dp[i][j]=-1;
    }
    for(int i=1;i<=q;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if(a[i] == b[i])
        {
            for(int j=0;j<30;j++)dp[a[i]][j]=((c[i] >> j) & 1);
            continue;
        }
        for(int j=29;j>=0;j--)
        {
            if(!((c[i] >> j) & 1))dp[a[i]][j]=dp[b[i]][j]=0;
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(a[i] == b[i])continue;
        for(int j=29;j>=0;j--)
        {
            if((c[i] >> j) & 1)
            {
                if(!dp[a[i]][j])dp[b[i]][j]=1;
                else if(!dp[b[i]][j])dp[a[i]][j]=1;
            }
        }
    }
    for(int i=29;i>=0;i--)
    {
        for(int j=1;j<=n;j++)adj[j].clear();
        for(int j=1;j<=q;j++)
        {
            if(a[j] == b[j])continue;
            if((c[j] >> i) & 1)
            {
                adj[a[j]].emplace_back(b[j]);
                adj[b[j]].emplace_back(a[j]);
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(dp[j][i] == -1  &&  !adj[j].empty())
            {
                int cnt=0;
                for(int it : adj[j])cnt += (dp[it][i] == 0);
                if(cnt)dp[j][i]=1;
                else
                {
                    dp[j][i]=0;
                    for(int it : adj[j])dp[it][i]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=0;j<30;j++)
        {
            if(dp[i][j] > 0)ans += (1 << j);
        }
        cout << ans << ' ';
    }
    return 0;
}