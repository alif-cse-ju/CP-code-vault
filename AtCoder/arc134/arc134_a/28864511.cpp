#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll a[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    ll ans=0,l,w;
    cin >> n >> l >> w;
    for(i=1;i<=n;i++)cin >> a[i];
    a[++n]=l;
    for(i=1;i<=n;i++)ans += (a[i]-(a[i-1]+(i-1 > 0 ? w : 0))+w-1)/w;
    cout << ans << '\n';
    return 0;
}