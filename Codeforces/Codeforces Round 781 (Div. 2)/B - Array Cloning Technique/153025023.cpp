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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,i,mx,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<ll,ll>cnt;
        for(i=0;i<n;i++)cin >> x, ++cnt[x];
        mx=-1;
        for(auto [x,y] : cnt)mx=max(mx, y);
        if(mx == n)cout << "0\n";
        else
        {
            n-=mx, ans=0;
            while(n > 0)
            {
                ans += (1+min(mx, n)), n-=mx, mx+=mx;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}