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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool pos;
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        pos=1;
        cin >> x;
        y=x,st.insert(x);
        for(i=1;i<n;i++)
        {
            cin >> x;
            if(x != y)
            {
                if(y < x)
                {
                    auto it=st.upper_bound(y);
                    if(it != st.end()  &&  *it < x)pos=0;
                }
                else
                {
                    auto it=st.lower_bound(y);
                    if(it != st.begin()  &&  *(--it) > x)pos=0;
                }
            }
            y=x,st.insert(x);
        }
        if(pos)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}