#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
const int N=2e5+5;
const int mod=1e9+7;
int l[N],r[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ordered_set<int>L,R;
        for(i=1;i<=n;i++)
        {
            cin >> l[i] >> r[i];
            L.insert(l[i]);
            R.insert(r[i]);
        }
        ans=INT_MAX;
        for(i=1;i<=n;i++)
        {
            x=R.order_of_key(l[i]);
            y=n-L.order_of_key(r[i]+1);
            ans=min(ans,x+y);
        }
        cout << ans << '\n';
    }
    return 0;
}