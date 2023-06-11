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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll j,X,xr;
    int cnt,i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        X=xr=0;
        for(j=0;j<61;j++)
        {
            cnt=0;
            for(i=1;i<=n;i++)cnt += ((a[i] >> j) & 1ll);
            if(cnt & 1)
            {
                X += (1ll << j);
                for(i=1;i<=n;i++)a[i] += (1ll << j);
            }
        }
        for(i=1;i<=n;i++)xr ^= a[i];
        if(xr)cout << "-1\n";
        else cout << X << '\n';
    }
    return 0;
}