#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
const int N=5e5+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,q,x,op,cnt=0;
    set<int>st;
    pair<int,int>temp;
    ordered_set<pair<int,int>>ost;
    cin >> q;
    while(q--)
    {
        cin >> op;
        if(op == 1)
        {
            ++cnt;
            cin >> x;
            a[cnt]=x;
            st.insert(cnt);
            ost.insert({x,-cnt});
        }
        else if(op == 2)
        {
            x=*(st.begin());
            st.erase(x);
            ost.erase({a[x],-x});
            cout << x << ' ';
        }
        else
        {
            l=(int)ost.size();
            temp=*(ost.find_by_order(l-1));
            x=-temp.second;
            st.erase(x);
            ost.erase(temp);
            cout << x << ' ';
        }
    }
    return 0;
}