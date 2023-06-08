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
const int mod=1e9+7;
const ll mx = (1 << 30);
int a[M];
ll dp[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    ll ans=0;
    int i,n,p,x;
    cin >> n >> p;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    vector<int>v;
    map<int,bool>visited;
    for(i=1;i<=n;i++)
    {
        x=a[i], ok=1;
        while(x)
        {
            if(visited.find(x) != visited.end())
            {
                ok=0;
                break;
            }
            if(x & 1)x /= 2;
            else
            {
                if(x%4)break;
                else x /= 4;
            }
        }
        if(ok)visited[a[i]]=1, v.emplace_back(a[i]);
    }
    vector<int>cnt(30,0);
    for(int it : v)
    {
        for(i=29;i>=0;i--)
        {
            if((it >> i) & 1)
            {
                ++cnt[i];
                break;
            }
        }
    }
    for(i=0;i<p;i++)
    {
        if(i < 30)dp[i]=cnt[i];
        if(i)dp[i] += dp[i-1];
        if(i-1)dp[i] += dp[i-2];
        if(dp[i] >= mod)dp[i] -= mod;
        ans += dp[i];
        if(ans >= mod)ans -= mod;
    }
    cout << ans;
    return 0;
}