#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
ll fib1[M],pw[M];
void PreCal()
{
    fib1[1]=1;
    pw[0]=pw[1]=2;
    for(int i=2;i<M;i++)
    {
        pw[i]=(pw[i-1]*pw[i-2])%mod;
        fib1[i]=(fib1[i-1]+fib1[i-2])%mod;
    }
}
ll BigMod(ll val,ll pow)
{
    ll res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (fib1[n]*((pw[n]*BigMod(2,mod-2))%mod))%mod << '\n';
    }
    return 0;
}