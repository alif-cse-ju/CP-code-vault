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
const int M=5e5+5;
const int N=1e6+5;
const int mod=998244353;
const int sz = (1 << 22);
int a[N],dp[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++) cin >> a[i], dp[a[i]]=a[i];
    for(int i=0;i<22;i++)
    {
        for(int j=0;j<sz;j++)
        {
            if((j >> i) & 1)dp[j]=max(dp[j], dp[(j ^ (1 << i))]);
        }
    }
    for(int i=1;i<=n;i++)cout << dp[((sz-1) ^ a[i])] << ' ';
    return 0;
}