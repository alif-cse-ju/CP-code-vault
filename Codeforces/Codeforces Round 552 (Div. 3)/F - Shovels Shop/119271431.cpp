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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
ll a[N],dp[N];
pair<int,int>offer[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,m,n;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    ++m,offer[1].first=1;
    for(i=2;i<=m;i++)cin >> offer[i].first >> offer[i].second;
    sort(a+1,a+n+1);
    n=k;
    for(i=1;i<=n;i++)a[i]+=a[i-1];
    for(i=1;i<=n;i++)
    {
        dp[i]=LLONG_MAX;
        for(j=1;j<=m;j++)
        {
            if(offer[j].first <= i)dp[i]=min(dp[i],dp[i-offer[j].first]+a[i]-a[i-offer[j].first+offer[j].second]);
        }
    }
    cout << dp[n];
    return 0;
}