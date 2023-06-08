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
int a[M];
ll dp[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=2;i<N;i++)dp[i]=1;
    for(int i=n;i;i--)
    {
        vector<int>divs;
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j)continue;
            divs.emplace_back(a[i]/j);
            dp[j] += dp[j+1];
            if(dp[j] >= mod)dp[j]-=mod;
        }
        if(divs.back() == sqrt(a[i]))divs.pop_back();
        while(!divs.empty())
        {
            int x=divs.back(); divs.pop_back();
            dp[x] += dp[x+1];
            if(dp[x] >= mod)dp[x] -= mod;
        }
    }
    cout << dp[1];
    return 0;
}