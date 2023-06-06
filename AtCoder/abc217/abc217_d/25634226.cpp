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

const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,q,x,y;
    cin >> l >> q;
    set<pair<int,int>>st;
    st.insert({0,l});
    st.insert({INT_MAX,INT_MAX});
    while(q--)
    {
        cin >> x >> y;
        auto it=st.lower_bound({y,INT_MAX});
        if(x == 1)
        {
            auto [l,r]=*(--it);
            st.erase({l,r});
            st.insert({l,y});
            st.insert({y,r});
        }
        else
        {
            auto [l,r]=*(--it);
            cout << r-l << '\n';
        }
    }
    return 0;
}
