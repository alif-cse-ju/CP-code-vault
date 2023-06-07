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
int a[M],dp[515];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<512;i++)dp[i]=550;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<512;j++)
        {
            if(dp[j] < a[i])
            {
                int xr=(a[i] ^ j);
                if(dp[xr] > a[i])dp[xr]=a[i];
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<512;i++)
    {
        if(dp[i] < 550)ans.emplace_back(i);
    }
    cout << (int)ans.size() << '\n';
    for(int it : ans)cout << it << ' ';
    return 0;
}