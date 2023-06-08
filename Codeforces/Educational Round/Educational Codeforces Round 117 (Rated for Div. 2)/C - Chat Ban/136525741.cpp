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
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll k,l,m,r,v,x,y;
    cin >> t;
    while(t--)
    {
        cin >> k >> x;
        if(k*k <= x)cout << 2*k-1 << '\n';
        else
        {
            l=1,r=2*k-1;
            while(l <= r)
            {
                m=(l+r) >> 1;
                y=min(k,m), v=(y*(y+1))/2;
                if(m > k)y=2*k-m-1, v+=(k*(k-1))/2-(y*(y+1))/2;
                if(v < x)l=m+1;
                else r=m-1;
            }
            cout << r+1 << '\n';
        }
    }
    return 0;
}