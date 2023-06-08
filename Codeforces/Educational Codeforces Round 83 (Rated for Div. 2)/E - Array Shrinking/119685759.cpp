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
const int M=5e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M],ans[M],dp[M][M];
int DP(int l,int r)
    if(l == r)return dp[l][r]=a[l];
    int &ans=dp[l][r];
    if(ans > -1)return dp[l][r];
    ans=0;
    for(int i=l;i<r;i++)
    {
        int lp=DP(l,i),rp=DP(i+1,r);
        if(lp  &&  rp  &&  lp == rp)return ans=lp+1;
    }
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    cin >> n;
    for(i=1; i<=n; i++)cin >> a[i];
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        ans[i]=INT_MAX;
        for(j=i;j;j--)
        {
            if(DP(j,i))ans[i]=min(ans[i],1+ans[j-1]);
        }
    }
    cout << ans[n];
    return 0;
}