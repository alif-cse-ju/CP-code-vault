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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll ans,m,mn,n,tmp,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        if(m == 1ll)ans=(n-1)*x;
        else if(n == 1ll)ans=(m-1)*x;
        else
        {
            ans=(m+n-2)*x;
            mn=min(m,n);
            m-=mn,n-=mn;
            tmp=(mn-1)*y;
            ans=min(ans,tmp+(m+n)*x);
            if(m & 1)tmp+=x,--m;
            if(n & 1)tmp+=x,--n;
            tmp += (m+n)*y;
            ans=min(ans,tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}