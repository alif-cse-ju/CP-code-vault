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
int n;
ll a[102];
ll Check(const int& bit)
    int i;
    ll gcd=0;
    for(i=1;i<=n;i++)
    {
        if((i & 1) == bit)gcd=__gcd(gcd,a[i]);
    }
    for(i=1;i<=n;i++)
    {
        if((!(i & 1)) == bit)
        {
            if(a[i]%gcd == 0)return 0;
        }
    }
    return gcd;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=Check(0);
        if(!ans)ans=Check(1);
        cout << ans << '\n';
    }
    return 0;
}