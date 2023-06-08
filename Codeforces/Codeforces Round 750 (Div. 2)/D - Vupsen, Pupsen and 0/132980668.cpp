#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll ans[M];
pair<ll,int>a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    ll lcm,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> x, a[i]={x,i};
        sort(a+1,a+n+1);
        for(i=2;i<=n;i+=2)
        {
            x=abs(a[i-1].first), y=abs(a[i].first);
            lcm=(x*y)/__gcd(x,y);
            ans[a[i].second]=(lcm/y)*(a[i].first < 0 ? -1ll : 1ll);
            ans[a[i-1].second]=(lcm/x)*(a[i-1].first < 0 ? 1ll : -1ll);
        }
        if(n & 1)
        {
            x=abs(a[n-2].first), y=abs(a[n-1].first), z=abs(a[n].first);
            lcm=((x+y)*z)/__gcd((x+y),z);
            ans[a[n].second]=(lcm/z)*(a[n].first < 0 ? -1ll : 1ll);
            ans[a[n-1].second]=(lcm/(x+y))*(a[n-1].first < 0 ? 1ll : -1ll);
            ans[a[n-2].second]=(lcm/(x+y))*(a[n-2].first < 0 ? 1ll : -1ll);
        }
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}