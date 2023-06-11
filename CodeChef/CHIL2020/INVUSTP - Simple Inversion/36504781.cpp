#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
const int N=1e5;
LL ans[N+2];
int main()
{
    FAST();
    int i,l,n,q,r,x,y;
    cin >> n >> q;
    ordered_set<int>ost;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        y=i-ost.order_of_key(x+1)-1;
        ost.insert(x),ans[i]=ans[i-1]+y;
    }
    while(q--)
    {
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << '\n';
    }
    return 0;
}