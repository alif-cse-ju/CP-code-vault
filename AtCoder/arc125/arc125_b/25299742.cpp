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

const int M=5e3+5;
const int N=1e6+5;
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,l,m,n,r,ans=0;
    cin >> n;
    for(i=1;i*i<=n;i++)
    {
        l=1,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(i*m <= n)l=m+1;
            else r=m-1;
        }
        ans+=(l-1+i%2)/2-(i-1+i%2)/2;
        ans%=mod;
    }
    cout << ans;
    return 0;
}
