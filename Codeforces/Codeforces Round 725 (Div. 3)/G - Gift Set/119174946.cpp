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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a,b,x,y,mn,ans;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> a >> b;
        if(x > y)swap(x,y);
        if(a > b)swap(a,b);
        if(a == b)cout << x/a << '\n';
        else
        {
            mn=(y-x)/(b-a);
            if(x/a < mn  ||  y/b < mn)cout << min(x/a,y/b) << '\n';
            else
            {
                ans=mn,x-=mn*a,y-=mn*b;
                mn=min(x/(a+b),y/(a+b));
                ans+=2*mn;
                x-=mn*(a+b),y-=mn*(a+b);
                if(x >= a  &&  y >= b)++ans;
                cout << ans << '\n';
            }
        }
    }
    return 0;
}