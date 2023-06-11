#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a,b,i,n,ans,odd,even;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        if(n & 1)ans=b;
        else ans=a;
        even=odd=0;
        while(n%2 == 0)++even,n/=2;
        for(i=3;i*i<=n;i+=2)
        {
            while(n%i == 0)++odd,n/=i;
        }
        if(n > 1)++odd;
        if(even)ans=max(ans,even*a);
        ans=max(ans,even*a+odd*b);
        ans=max(ans,min(1ll,even)*a+odd*b);
        ans=max(ans,even*a+min(1ll,odd)*b);
        ans=max(ans,min(1ll,even)*a+min(1ll,odd)*b);
        cout << ans << '\n';
    }
    return 0;
}