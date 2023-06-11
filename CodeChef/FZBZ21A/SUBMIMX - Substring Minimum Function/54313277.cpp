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
const int M=1e4+5;
const int N=5e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll ans,m,n,s;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(!m)ans=(n*(n+1))/2;
        else
        {
            n-=m, ++m, s=n%m;
            ans=m*(((n/m)*(n/m+1))/2);
            ans += s*((((n/m+1)*(n/m+2))/2) - (((n/m)*(n/m+1))/2));
        }
        cout << ans << '\n';
    }
    return 0;
}