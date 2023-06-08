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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned ll a,b,x,y;
    cin >> a >> b; x=b, y=0;
    if(a < b)cout << "-1";
    else
    {
        a -= b;
        if(a & 1)
        {
            cout << "-1";
            return 0;
        }
        for(int i=63;i;i--)
        {
            if((a >> i) & 1)
            {
                if(!((x >> (i-1)) & 1))x += (1ll << (i-1)), y += (1ll << (i-1));
                else
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
        cout << y << ' ' << x;
    }
    return 0;
}