#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int sz = 10005;

int a[102],b[102],dp[102][sz],n,x;

int DP(int i,int v)
{
    if(i > n)return (v == x);
    int &ans=dp[i][v];
    if(ans > -1)return ans;
    ans=DP(i+1,v+a[i]);
    ans|=DP(i+1,v+b[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,ok;
    cin >> n >> x;
    for(i=1;i<=n;i++)cin >> a[i] >> b[i];
    memset(dp,-1,sizeof(dp));
    ok=DP(1,0);
    if(ok)cout << "Yes";
    else cout << "No";
    return 0;
}
