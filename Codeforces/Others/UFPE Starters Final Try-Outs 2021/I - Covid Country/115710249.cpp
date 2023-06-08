#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
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
long long cnt[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,q,x;
    long long val;
    ordered_set<pair<long long,int>>ost;
    cin >> q >> n;
    for(i=0;i<n;i++)ost.insert({0,i});
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x >> val;
            auto it=ost.find_by_order(ost.order_of_key({cnt[x],x}));
            ost.erase(it);
            cnt[x]+=val;
            ost.insert({cnt[x],x});
        }
        else
        {
            cin >> val;
            cout << n-ost.order_of_key({val,INT_MAX}) << '\n';
        }
    }
    return 0;
}