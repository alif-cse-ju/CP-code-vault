#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int M=1e5+5;
const int N=2e5+5;
const int mod=998244353;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,W,x,y,z,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> W;
        ordered_set<int>ost;
        while(n--)
        {
            cin >> x;
            ost.insert(x);
        }
        ans=0;
        while(!ost.empty())
        {
            x=W;
            ++ans;
            while(!ost.empty()  &&  x >= *(ost.begin()))
            {
                y=ost.order_of_key(x+1);
                z=*(ost.find_by_order(y-1));
                x-=z;
                ost.erase(ost.find_by_order(y-1));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//