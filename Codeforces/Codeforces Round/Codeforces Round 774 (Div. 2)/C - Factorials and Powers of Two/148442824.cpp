#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll fact[20];
void PreCal()
    fact[0]=1;
    for(int i=2;i<20;i++)
    {
        fact[i-1]=fact[i-2]*i;
        if(fact[i-1] > 1e12)break;
    }
int Cal(const ll& n)
    ll rem,sum;
    int ans=__builtin_popcountll(n),i,j,l=(1 << 15);
    for(i=0;i<l;i++)
    {
        sum=0;
        for(j=0;j<15;j++)
        {
            if((i >> j) & 1)sum += fact[j];
        }
        if(sum > n)continue;
        rem=n-sum;
        if(((i >> 0) & 1)  &&  ((i >> 0) & 1) == ((rem >> 0) & 1))continue;
        if(((i >> 1) & 1)  &&  ((i >> 1) & 1) == ((rem >> 1) & 1))continue;
        ans=min(ans, __builtin_popcount(i) + __builtin_popcountll(rem));
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    int t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << Cal(n) << '\n';
    }
    return 0;
}