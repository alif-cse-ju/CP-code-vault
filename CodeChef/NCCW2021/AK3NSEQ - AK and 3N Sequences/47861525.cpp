#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
int a[N];
ll dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    ll ans,sum=0;
    cin >> n;
    for(i=1;i<=3*n;i++)cin >> a[i];
    dp[2*n+1]=LLONG_MAX;
    priority_queue<int>pq;
    for(i=3*n;i>2*n;i--)sum+=a[i],pq.emplace(a[i]);
    for(i=2*n;i>=n;i--)
    {
        dp[i]=min(dp[i+1],sum);
        if(a[i] < pq.top())sum-=pq.top()-a[i],pq.pop(),pq.emplace(a[i]);
    }
    while(!pq.empty())pq.pop();
    for(i=1,sum=0;i<=n;i++)pq.emplace(-a[i]),sum+=a[i];
    ans=sum-dp[n];
    for(i=n+1;i<=2*n;i++)
    {
        if(a[i] > -pq.top())sum+=a[i]+pq.top(),pq.pop(),pq.emplace(-a[i]);
        ans=max(ans,sum-dp[i]);
    }
    cout << ans;
    return 0;
}