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
const int N=2e6+5;
const int mod=1e9+7;

const ll MAX=5000000000000000000LL;

int a[18],b[18],n;
ll dp[18][1 << 18],x,y;

ll DP(int pos,int mask)
{
    if(pos == n)return 0;
    ll &ans=dp[pos][mask];
    if(ans > -1)return ans;
    ans=MAX;
    int cnt=0,i;
    for(i=0;i<n;i++)
    {
        cnt += ((mask >> i) & 1);
        if((mask >> i) & 1)continue;
        if(MAX/max(1, abs(i+(__builtin_popcount(mask)-cnt)-pos)) < y)continue;
        if(((MAX - abs(i+(__builtin_popcount(mask)-cnt)-pos)*y) / max(1, abs(a[i]-b[pos]))) < x)continue;
        ans=min(ans, abs(i+(__builtin_popcount(mask)-cnt)-pos)*y + abs(a[i]-b[pos])*x + DP(pos+1,mask | (1 << i)));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    cin >> n >> x >> y;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)cin >> b[i];
    memset(dp,-1,sizeof(dp));
    cout << DP(0,0);
    return 0;
}