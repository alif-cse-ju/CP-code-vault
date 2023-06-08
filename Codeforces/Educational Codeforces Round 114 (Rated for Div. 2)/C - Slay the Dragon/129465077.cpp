#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=4e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,n;
    ll ans,sum=0,x,xx,y,yy;
    ordered_set<ll>ost;
    cin >> n;
    for(i=0;i<n;i++)cin >> x,sum += x,ost.insert(x);
    cin >> m;
    while(m--)
    {
        x=-1e13,y=1e13;
        cin >> xx >> yy;
        l=ost.order_of_key(xx);
        y=*(ost.find_by_order(min(l,n-1)));
        if(y == xx)
        {
            cout << max(0ll,yy-sum+y) << '\n';
            continue;
        }
        x=*(ost.find_by_order(max(0,l-1)));
        cout << min((x < xx ? xx-x : 0ll)+max(0ll,yy-(sum-x)),(y > xx ? 0ll : xx-y)+max(0ll,yy-(sum-y))) << '\n';
    }
    return 0;
}