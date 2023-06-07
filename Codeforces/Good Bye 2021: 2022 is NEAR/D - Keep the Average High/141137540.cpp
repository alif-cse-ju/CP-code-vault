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
const int M=5e4+5;
const int N=2e6+5;
const int mod=1e9+7;
int n;
ll a[M],dp[M][3],x;
ll DP(int i,int cnt)
    if(i > n)return 0;
    ll &ans=dp[i][cnt];
    if(ans > -1)return ans;
    ans=DP(i+1,0);
    if(!cnt)ans=max(ans, 1+DP(i+1,1));
    else if(cnt == 1  &&  a[i-1]+a[i] >= 2*x)ans=max(ans, 1+DP(i+1,2));
    else if(cnt == 2  &&  a[i-1]+a[i] >= 2*x  &&  a[i-2]+a[i-1]+a[i] >= 3*x)ans=max(ans, 1+DP(i+1,2));
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i], dp[i][0]=dp[i][1]=dp[i][2]=-1;
        cin >> x;
        cout << DP(1,0) << '\n';
    }
    return 0;
}