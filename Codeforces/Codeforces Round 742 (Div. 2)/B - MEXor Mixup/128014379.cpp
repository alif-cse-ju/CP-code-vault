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
const int N=1e6+5;
const int mod=998244353;
int XOR(int n)
    if(n%4 == 0)return n;
    if(n%4 == 1)return 1;
    if(n%4 == 2)return n+1;
    return 0;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,t,xr;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        xr=XOR(a-1);
        if(xr == b)cout << a << '\n';
        else cout << a+1+((b ^ xr) == a) << '\n';
    }
    return 0;
}