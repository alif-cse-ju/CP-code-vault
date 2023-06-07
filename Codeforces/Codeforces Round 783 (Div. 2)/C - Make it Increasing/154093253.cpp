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
const int sz = 5005;
ll a[sz],b[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    ll ans=LLONG_MAX;
    for(int i=1;i<=n;i++)
    {
        ll cnt=0;
        b[i]=0;
        for(int j=i-1;j;j--)
        {
            ll v=abs(b[j+1]);
            v = (v+a[j]-1)/a[j];
            b[j]=-(v*a[j]), cnt+=v;
            if(b[j] == b[j+1])++cnt, b[j]-=a[j];
        }
        for(int j=i+1;j<=n;j++)
        {
            ll v=b[j-1];
            v = (v+a[j]-1)/a[j];
            b[j]=v*a[j], cnt+=v;
            if(b[j] == b[j-1])++cnt, b[j]+=a[j];
        }
        ans=min(ans,cnt);
    }
    cout << ans;
    return 0;
}