#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long a,b,i,l,m,r,ans,cur;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        ans=0;
        for(i=sqrt(a);i;i--)
        {
            l=i+1,r=b;
            while(l <= r)
            {
                m=(l+r) >> 1ll;
                if(m*i+i <= a)l=m+1;
                else r=m-1;
            }
            ans+=l-i-1;
        }
        cout << ans << '\n';
    }
    return 0;
}