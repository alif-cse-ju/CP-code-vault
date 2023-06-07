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

ll a[M],dpF[M],dpR[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=2;i<=n;i++)
    {
        if(a[i] < a[i-1])dpF[i]=a[i-1]-a[i];
        dpF[i] += dpF[i-1];
    }
    for(int i=n-1;i;i--)
    {
        if(a[i] < a[i+1])dpR[i]=a[i+1]-a[i];
        dpR[i] += dpR[i+1];
    }
    while(q--)
    {
        int l,r;cin >> l >> r;
        if(l <= r)cout << dpF[r]-dpF[l] << '\n';
        else cout << dpR[r]-dpR[l] << '\n';
    }
    return 0;
}
