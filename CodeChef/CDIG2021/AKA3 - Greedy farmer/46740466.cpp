#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long n,a[M];
long long Check(int val)
{
    int i;
    long long cnt=0;
    for(i=1;i<=n;i++)cnt+=(a[i]+val-1)/val;
    return cnt-n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long i,k,l,m,r,ans;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    l=1,r=1e9;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(Check(m) <= k)ans=m,r=m-1;
        else l=m+1;
    }
    cout << ans;
    return 0;
}