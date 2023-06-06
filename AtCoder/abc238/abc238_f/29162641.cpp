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

const int sz = 305;

ll dp[sz][sz][sz];
int a[sz],n,p[sz],q[sz];

ll DP(int id,int minNotTaken,int rem)
{
    if(!rem)return 1;
    if(id > n)return 0;
    ll &ans=dp[id][minNotTaken][rem];
    if(ans > -1)return ans;
    ans=DP(id+1,min(minNotTaken, a[id]), rem);
    if(a[id] < minNotTaken)
    {
        ans += DP(id+1, minNotTaken, rem-1);
        if(ans >= mod)ans -= mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> p[i];
    for(i=1;i<=n;i++)cin >> q[i];
    for(i=1;i<=n;i++)a[p[i]]=q[i];
    memset(dp,-1,sizeof(dp));
    cout << DP(1,n+1,k);
    return 0;
}