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
ll mx=1000000000000000000;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        ll a,b,c,x,y,z;cin >> a >> b >> c;
        x=a, z=x+c, y=z+b;
        if(x%y == a  &&  y%z == b  &&  z%x == c  &&  x <= mx  &&  y <= mx  &&  z <= mx)cout << x << ' ' << y << ' ' << z << '\n';
        else
        {
            y=b, x=y+a, z=x+c;
            if(x%y == a  &&  y%z == b  &&  z%x == c  &&  x <= mx  &&  y <= mx  &&  z <= mx)cout << x << ' ' << y << ' ' << z << '\n';
            else
            {
                z=c, y=z+b, x=y+a;
                cout << x << ' ' << y << ' ' << z << '\n';
            }
        }
    }
    return 0;
}