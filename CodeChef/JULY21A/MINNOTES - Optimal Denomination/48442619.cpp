#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
ll a[M],gcdf[M],gcdr[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    ll ans,sum,tmp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=gcdr[n+1]=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i],gcdf[i]=__gcd(a[i],gcdf[i-1]);
        }
        if(n == 1)
        {
            cout << "1\n";
            continue;
        }
        for(i=n;i;i--)gcdr[i]=__gcd(a[i],gcdr[i+1]);
        ans=LLONG_MAX;
        for(i=1;i<=n;i++)
        {
            tmp=__gcd(gcdf[i-1],gcdr[i+1]);
            tmp=(sum-a[i])/tmp+1;
            ans=min(ans,tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}