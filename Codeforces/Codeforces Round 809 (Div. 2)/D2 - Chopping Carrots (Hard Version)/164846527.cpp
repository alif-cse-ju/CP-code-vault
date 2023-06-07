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
const int mod=1e9+7;

int a[M],dp[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=0;i<=a[1];i++)dp[i]=0;
        for(int i=1;i<=n;i++)
        {
            int nxt=a[n]+100;
            for(int j=1;j<=min(a[i],k);j=(a[i]/(a[i]/j))+1)
            {
                int v=a[i]/j;
                dp[v+1]=max(dp[v+1], nxt), nxt=v;
            }
            dp[0]=max(dp[0], nxt);
        }
        int ans=INT_MAX;
        for(int i=0;i<=a[1];i++)
        {
            if(i)dp[i]=max(dp[i], dp[i-1]);
            ans=min(ans, dp[i]-i);
        }
        cout << ans << '\n';
    }
    return 0;
}