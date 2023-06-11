#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,x,y;
    int cur,i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0, cur=1;
        for(i=2;i<=n;i++)
        {
            x=a[cur]*(n-cur+1)-a[n];
            y=a[cur]*(i-cur+1)+a[i]*(n-i)-a[n];
            if(y < x)ans += a[cur]*(i-cur+1)-a[i], cur=i;
        }
        if(cur != n)ans += (n-cur+1)*a[cur]-a[n];
        cout << max(0ll,ans) << '\n';
    }
    return 0;
}