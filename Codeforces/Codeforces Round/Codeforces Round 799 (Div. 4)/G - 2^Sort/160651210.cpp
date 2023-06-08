#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll a[M];
int n,sum[M];
void Update(int i)
    while(i <= n)++sum[i], i+=(i & -i);
int Query(int i)
    int ans=0;
    while(i)ans += sum[i], i-=(i & -i);
    return ans;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k;cin >> n >> k;
        for(int i=1;i<=n;i++)cin >> a[i], sum[i]=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]*2ll > a[i-1])Update(i);
        }
        int ans=0;
        for(int i=1;i+k<=n;i++)ans += (Query(i+k)-Query(i) == k);
        cout << ans << '\n';
    }
    return 0;
}