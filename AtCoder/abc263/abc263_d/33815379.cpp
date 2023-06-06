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

ll a[M],pre[M],suf[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    ll l,r;cin >> l >> r;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)pre[i]=min(pre[i-1]+a[i], i*l);
    for(int i=n;i;i--)suf[i]=min(suf[i+1]+a[i], (n-i+1)*r);
    ll ans=pre[n];
    for(int i=0;i<=n;i++)ans=min(ans, pre[i]+suf[i+1]);
    cout << ans;
    return 0;
}
