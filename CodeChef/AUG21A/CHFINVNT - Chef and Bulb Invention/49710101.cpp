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
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,k,m,n,p,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> p >> k;
        ++p;
        if(p%k == 0)ans=n-(n/k-p/k);
        else
        {
            m=n%k;
            if(!m)m=k;
            m=min(m,p%k-1);
            ans=((n+k-1)/k)*m;
            m=p%k-m-1;
            ans+=m*(n/k);
            ans+=(p+k-1)/k;
        }
        cout << ans << '\n';
    }
    return 0;
}