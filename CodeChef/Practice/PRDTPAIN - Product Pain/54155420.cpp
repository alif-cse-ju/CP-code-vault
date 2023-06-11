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
const int M=3e3+5;
const int N=2e6+5;
const int mod=1e9+7;
ll a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,m;
    int i,j,n,p,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0;
        for(i=3;i<=n;i++)
        {
            for(j=i-2;j;j--)
            {
                m=(a[i]+a[j])/2;
                auto it=lower_bound(a+j+1,a+i,m);
                p=it-a;
                ans += max((a[i]-a[p])*(a[p]-a[j]), (a[i]-a[p-1])*(a[p-1]-a[j]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}